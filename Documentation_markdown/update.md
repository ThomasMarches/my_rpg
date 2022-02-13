<h1>Update function</h1>
<p>On this page, we will explain how the update function of a game_object works.</p>
<hr class="major">
<h2>What is an update function ?</h2>
<p>The update function will be called at every turn of the loop. It's used to update anything about an object. For exemple an animation, a cooldown, to make an object shoot, etc, etc...</p>
<pre><font color="red">void</font> update_objects(<font color="red">scene_t *</font>scene, <font color="red">game_object_t *</font>object, <font color="red">game_t *</font>game)
{
	<font color="red">bool</font> ret = true;
	<font color="red">game_object_t *</font>tmp = NULL;<br>
	for (; object; object = object->next, ret = true) {
		if (object->update != NULL)
			ret = object->update(object, scene);
		if (ret == false) {
			tmp = object;
			object = object->next;
			destroy_game_object(scene, tmp);
		}
		if (object == NULL)
			<font color="blue">return</font>;
	}
}</pre>
<p>We will go trough all the object_list to check every object's update function, if the function isnt null, it will call the object's update function. It will also be used to destroy the objects if the update function returns false.</p>
<hr class="major">
<h2>Create an update function</h2>
<p>To use an update function, you need to take care the arguments are the one needed. As we can see in the game_object structure, the update function take as argument a  game_object_t * and scene_t *. In this exemple we initialize a  game_object_t *object which is a planet, and we set it's update function to &<font color="blue">rpg_galaxie_update_planet.</font></p>
<pre><font color="red">game_object_t *</font>rpg_galaxie_create_planet(<font color="red">game_object_t *</font>last, <font color="red">char *</font>path, <font color="red">sfVector2f </font>pos)
{
	<font color="red">game_object_t *</font>object = create_game_object(last, path, pos, PLANET);<br>
	object->update = &<font color="blue">rpg_galaxie_update_planet</font>;
	object->box = (sfIntRect) {pos.x, pos.y, PLANET_WIDTH, PLANET_HEIGHT};
	<font color="blue">return</font> (object);
}</pre>
<p>Now that we got our planet, we create the update function rpg_galaxie_update_planet(). In this exemple, the update function is used to see if the player colladed with a planet, and if he did, we switch scene.</p>
<pre><font color="red">bool</font> rpg_galaxie_update_planet(<font color="red">game_object_t *</font>object, <font color="red">scene_t *</font>scene)
{
	<font color="red">game_object_t *</font>tmp = scene->objects_list;<br>
	for (; tmp; tmp = tmp->next) {
		if (tmp->type == (int) PLAYER)
			<font color="blue">break</font>;
	}
	if (sfIntRect_intersects(&tmp->box, &object->box, NULL))
		scene->display = MAIN_MENU_SCENE;
	<font color="blue">return</font> (true);
}</pre>
<p>So to conclude, when the user will collade with a planet, the scene->display will be set to MAIN_MENU_SCENE, which means we switched the displaying scene of the game.</p>
<h4>Argument of an update function</h4>
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
			<td>the game_object_t * that called the update function</td>
			<td><font color="red">game_object_t *</td></font>
		</tr>
		<tr>
			<td>scene</td>
			<td>A pointer on the scene to be able to switch scene and to access the scene->object_list.</td>
			<td><font color="red">scene_t *</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
