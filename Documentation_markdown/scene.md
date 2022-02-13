<h1>Scene</h1>
<p>On this page, we will explain how works the scene handling and how to handle events on a scene.</p>
<hr>
<h2>What is a scene concretely?</h2>
<p>Every different window of our game is a scene. The menu, the galaxy, a village, the pause menu, the fight, they're all different scenes.</p>
<h2>Scene_index</h2>
<p>To know which scene we are actually on and to switch scene, inside my_rpg.h we got an enum of every scene of the game.</p>
<pre><font color="green">typedef</font><font color="red"> enum</font> {
	<font color="orange">MAIN_MENU_SCENE</font>,
	<font color="orange">OPTION_SCENE</font>,
	<font color="orange">INFOS_SCENE</font>,
	<font color="orange">END_SCENE</font>,
	<font color="orange">IN_GAME_MENU_SCENE</font>,
	<font color="orange">GALAXIE_SCENE</font>,
	<font color="orange">FIGHT_SCENE</font>,
	<font color="orange">FIGHT_PAUSE_SCENE</font>,
	<font color="orange">VILLAGE_SCENE</font>,
	<font color="orange">NULL_SCENE</font>,
} <font color="red">scene_index</font>;</pre>
<h2>Create a scene.</h2>
<p>To create a scene, it uses the json parser and the json_constructors. Here is an exemple of the json configuration file for the how to play scene.</p>
<pre>{
	"<font color="purple">scene</font>": {
		"<font color="orange">id</font>": 2,
		"<font color="orange">z_index_deepth</font>": 0,
		"<font color="orange">draw_id</font>": 0,
		"<font color="orange">update_id</font>": 0,
		"<font color="orange">events_ids</font>": [
			[0, 0],
			[1, 9],
			[2, 5]
		],
		"<font color="orange">background_color</font>": [0, 0, 0, 0],
		"<font color="orange">objects_list</font>": [
			{
				"<font color="red">type</font>": 7,
				"<font color="red">string</font>": "How to play",
				"<font color="red">font</font>": "templates/font/space.ttf",
				"<font color="red">pos</font>": [400, 100],
				"<font color="red">style</font>": 0,
				"<font color="red">size</font>": 100
			},
			{
				"<font color="red">type</font>": 2,
				"<font color="red">texture_path</font>": "templates/menu/return2.png",
				"<font color="red">pos</font>": [820, 700],
				"<font color="red">callback_id</font>": 4,
				"<font color="red">sound_path</font>": "templates/sounds/ui_change_selection.ogg",
				"<font color="red">frame_keys</font>": [
					[0, 0, 280, 163],
					[290, 0, 280, 163],
					[570, 0, 280, 163]
				]
			},
			{
				"<font color="red">type</font>": 0,
				"<font color="red">texture_path</font>": "templates/menu/arrow_left.png",
				"<font color="red">callback_id</font>": 0,
				"<font color="red">pos</font>": [10, 464]
			},
			{
				"<font color="red">type</font>": 0,
				"<font color="red">texture_path</font>": "templates/menu/arrow_right.png",
				"<font color="red">callback_id</font>": 1,
				"<font color="red">pos</font>": [1810, 464]
			},
			{
				"<font color="red">type</font>": 3,
				"<font color="red">texture_path</font>": "templates/menu/menu_bg_test_with_text.jpg",
				"<font color="red">pos</font>": [0, 0]
			}
		]
	}
}</pre>
<table>
	<thead>
		<tr>
			<th>Value's name</th>
			<th>Description</th>
			<th>Type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>id</td>
			<td>Index of the scene inside my_rpg.h</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>z_index_deepth</td>
			<td>Deepth of the scene for drawing <a href="game_object.html">game_objects</a>.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>draw_id</td>
			<td>id of the draw function of the scene ( leave 0 ).</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>update_id</td>
			<td>id of the update function of the scene ( leave 0 ).</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>events_ids</td>
			<td>Contains all the events of the scene.</td>
			<td><font color="red">Array</td></font>
		</tr>
		<tr>
			<td>background_color</td>
			<td>Background color of the scene.</td>
			<td><font color="red">sfColor ( in RGBA )</td></font>
		</tr>
		<tr>
			<td>objects_list</td>
			<td>Contains all the objects of the scene.</td>
			<td><font color="red">Array*</td></font>
		</tr>
	</tbody>
</table>
<hr>
<h2>Event_ids</h2>
<p>Here we will explain you how we handle every event inside a scene. First of all, we got an enum and a function's table pointer that contains every function that en event will have to call. For exemple, the first enum is <font color="orange">CLOSE_SCENE_EVENT_ID</font> and it will call &<font color="blue">close_scene.</font></p>
<pre><font color="red">enum</font> {
	<font color="orange">CLOSE_SCENE_EVENT_ID</font>,
	<font color="orange">CLICK_ON_EVENT_ID</font>,
	<font color="orange">RETURN_TO_MAIN_MENU_EVENT_ID</font>,
	<font color="orange">GALAXIE_MOVE_EVENT_ID</font>,
	<font color="orange">TRIGGER_IN_GAME_MENU_EVENT_ID</font>,
	<font color="orange">OPEN_INVENTORY_ID</font>,
	<font color="orange">FIGHT_PAUSE_ID</font>,
	<font color="orange">VILLAGE_MOVE_EVENT_ID</font>,
	<font color="orange">MAX_SCENE_EVENT_ID</font>
};

<font color="red">void</font> return_to_main_menu(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> galaxie_move_event(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> village_move_event(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> trigger_in_game_menu(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> return_to_main_menu(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> open_inventory(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);
<font color="red">void</font> pause_fight(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window);

<font color="red">static void</font> (*EVENT_SCENE_FP[]) (<font color="red">sfEvent</font> event, <font color="red">game_t *</font> game, <font color="red">scene_t *</font> scene, <font color="red">sfRenderWindow *</font>window) = {
	&<font color="blue">close_scene</font>,
	&<font color="blue">is_click_on_object</font>,
	&<font color="blue">return_to_main_menu</font>,
	&<font color="blue">galaxie_move_event</font>,
	&<font color="blue">trigger_in_game_menu</font>,
	&<font color="blue">open_inventory</font>,
	&<font color="blue">pause_fight</font>,
	&<font color="blue">village_move_event</font>,
};</pre>
<p>But now how do we link it to a particular event? If you look up in the scene configuration file, you can see this:</p>
<pre>"<font color="orange">events_ids</font>": [
	[0, 0],
	[1, 9],
	[2, 5]
],</pre>
<p>The first number is the enum that we've seen right before and the second number is the id of the <font color="red">sfEvent</font> you want to link it to.</p>
<p>Here you can see the list of every CSFML <font color="red">sfEvent</font>.</p>
<pre><font color="green">typedef</font> <font color="red">enum</font>
{
	<font color="orange">sfEvtClosed,                </font> ///< The window requested to be closed (no data)
	<font color="orange">sfEvtResized,               </font> ///< The window was resized (data in event.size)
	<font color="orange">sfEvtLostFocus,             </font> ///< The window lost the focus (no data)
	<font color="orange">sfEvtGainedFocus,           </font> ///< The window gained the focus (no data)
	<font color="orange">sfEvtTextEntered,           </font> ///< A character was entered (data in event.text)
	<font color="orange">sfEvtKeyPressed,            </font> ///< A key was pressed (data in event.key)
	<font color="orange">sfEvtKeyReleased,           </font> ///< A key was released (data in event.key)
	<font color="orange">sfEvtMouseWheelMoved,       </font> ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
	<font color="orange">sfEvtMouseWheelScrolled,    </font> ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
	<font color="orange">sfEvtMouseButtonPressed,    </font> ///< A mouse button was pressed (data in event.mouseButton)
	<font color="orange">sfEvtMouseButtonReleased,   </font> ///< A mouse button was released (data in event.mouseButton)
	<font color="orange">sfEvtMouseMoved,            </font> ///< The mouse cursor moved (data in event.mouseMove)
	<font color="orange">sfEvtMouseEntered,          </font> ///< The mouse cursor entered the area of the window (no data)
	<font color="orange">sfEvtMouseLeft,             </font> ///< The mouse cursor left the area of the window (no data)
	<font color="orange">sfEvtJoystickButtonPressed, </font> ///< A joystick button was pressed (data in event.joystickButton)
	<font color="orange">sfEvtJoystickButtonReleased,</font> ///< A joystick button was released (data in event.joystickButton)
	<font color="orange">sfEvtJoystickMoved,         </font> ///< The joystick moved along an axis (data in event.joystickMove)
	<font color="orange">sfEvtJoystickConnected,     </font> ///< A joystick was connected (data in event.joystickConnect)
	<font color="orange">sfEvtJoystickDisconnected,  </font> ///< A joystick was disconnected (data in event.joystickConnect)
	<font color="orange">sfEvtTouchBegan,            </font> ///< A touch event began (data in event.touch)
	<font color="orange">sfEvtTouchMoved,            </font> ///< A touch moved (data in event.touch)
	<font color="orange">sfEvtTouchEnded,            </font> ///< A touch event ended (data in event.touch)
	<font color="orange">sfEvtSensorChanged,         </font> ///< A sensor value changed (data in event.sensor)
	<font color="orange">sfEvtCount,                 </font> ///< Keep last -- the total number of event types
} <font color="red">sfEventType</font>;</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
