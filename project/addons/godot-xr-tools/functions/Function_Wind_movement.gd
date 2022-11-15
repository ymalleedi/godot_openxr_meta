@tool
class_name Function_WindMovement
extends MovementProvider

## Signal invoked when changing active wind areas
signal wind_area_changed(active_wind_area)

## Movement provider order
@export var order : int = 25

## Drag multiplier for the player
@export var drag_multiplier : float = 1.0

# Wind area
@onready var _sense_area: Area3D = $Area3D

# Array of wind areas the player is in
var _in_wind_areas := Array()

# Currently active wind area
var _active_wind_area: WindArea

# Called when the node enters the scene tree for the first time.
func _ready():
	# In Godot 4 we must now manually call our super class ready function
	super._ready()

	# Skip if running in the editor
	if Engine.is_editor_hint():
		return

	# Reparent the sense area to the camera
	var camera = XRHelpers.get_xr_camera(self)
	if camera:
		self.remove_child(_sense_area)
		camera.add_child(_sense_area)

	# Subscribe to area notifications
	_sense_area.connect("area_entered", _on_area_entered)
	_sense_area.connect("area_exited", _on_area_exited)

func _on_area_entered(area: Area3D):
	# Skip if not wind area
	var wind_area = area as WindArea
	if !wind_area:
		return

	# Save area and set active
	_in_wind_areas.push_front(wind_area)
	_active_wind_area = wind_area

	# Report the wind area change
	emit_signal("wind_area_changed", _active_wind_area)

func _on_area_exited(area: Area3D):
	# Erase from the wind area
	_in_wind_areas.erase(area)
	
	# If we didn't leave the active wind area then we're done
	if area != _active_wind_area:
		return

	# Select a new active wind area
	if _in_wind_areas.is_empty():
		_active_wind_area = null
	else:
		_active_wind_area = _in_wind_areas.front()

	# Report the wind area change
	emit_signal("wind_area_changed", _active_wind_area)

# Perform jump movement
func physics_movement(delta: float, player_body: PlayerBody):
	# Skip if no active wind area
	if !_active_wind_area:
		return

	# Calculate the global wind velocity of the wind area
	var wind_velocity := _active_wind_area.global_transform.basis * _active_wind_area.wind_vector

	# Drag the player into the wind
	var drag_factor := _active_wind_area.drag * drag_multiplier * delta
	drag_factor = clamp(drag_factor, 0.0, 1.0)
	player_body.velocity = player_body.velocity.lerp(wind_velocity, drag_factor)

# This method verifies the MovementProvider has a valid configuration.
func _get_configuration_warning():
	# Call base class
	return super._get_configuration_warning()
