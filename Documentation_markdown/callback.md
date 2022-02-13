<h1>Callback function</h1>
<p>On this page, we will explain how the callback function of a game_object</a> works.</p>
<hr>
<h2>What is a callback function ?</h2>
<p>The callback function will be called if you click on the object. Here you can see how the callback function is called.</p>
<pre><font color="red">void</font> is_click_on_object(<font color="red">sfEvent</font> event, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene, <font color="red">sfRenderWindow *</font>window)
{
	<font color ="red">game_object_t *</font>object = scene->objects_list;
	<font color ="red">sfMouseButtonEvent</font> mouse_button = event.mouseButton;
	<font color ="red">sfVector2i</font> pos = sfMouse_getPositionRenderWindow(game->window->window);
	<font color ="red">int</font> x = pos.x;
	<font color ="red">int</font> y = pos.y;<br>
	if (mouse_button.button != sfMouseLeft)
		<font color="blue">return</font>;
	for (; object; object = object->next) {
		if (object->callback != NULL && sfIntRect_contains(&object->box, x, y))
			object->callback(object, scene);
	}
}</pre>
<p>We will go trough all the object_list to check every object's callback function, if the function isnt null and we clicked on the object, it will call the object's callback function.</p>
<hr>
<h2>Create a callback function</h2>
<p>To use a callback function, you need to take care the arguments are the one needed. As we can see in the game_object structure, the callback function take a game_object and void *pointer. In this exemple we initialize a game_object_t *button, and we set its callback function to &play_button_function.</p>
<pre><font color="red">game_object_t *</font>rpg_in_game_menu_create_play_button(<font color="red">void</font>)
{
	<font color="red">game_object_t *</font>object = NULL;<br>
	object = create_text_button(object, (<font color="red">char *</font>)CONTINUE_BUTTON_PATH, (<font color="red">sfVector2f</font>) {CONTINUE_BUTTON_X, CONTINUE_BUTTON_Y});
	object->callback = &play_button_function;
	<font color="blue">return</font> (object);
}</pre>
<p>Now that we got a game_object_t *</a>button, we create the callback function play_button_function(). In this exemple, we will cast the void pointer to a scene_t pointer to switch scene.</p>
<pre><font color="red">void</font> play_button_function(<font color="red">game_object_t *</font>object, <font color="red">void *</font>pt)
{
	<font color="red">scene_t *</font>scene = (<font color="red">scene_t *</font>)pt;<br>
	scene->display = GALAXIE_SCENE;
}</pre>
<p>So to conclude, when the user will click on the game_object_t *button, the scene->display will be set to GALAXIE_SCENE, which means we switched the displaying scene of the game.</p>
<h4>Argument of a callback function.</h4>
<table>
	<thead>
		<tr>
			<th>Name</th>
			<th>Description</th>
			<th>Type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>object</td>
			<td>the game_object_t *</a> which we clicked on.</td>
			<td><font color="red">game_object_t *</td></font>
		</tr>
		<tr>
			<td>pt</td>
			<td>A void pointer to make the callback function as generic as possible.</td>
			<td><font color="red">void *</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
