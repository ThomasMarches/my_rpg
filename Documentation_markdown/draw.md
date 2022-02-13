<h1>Draw function</h1>
<p>On this page, we will explain how the draw function of a game_object works.</p>
<hr>
<h2>How does it work ?</h2>
<p>The draw function will be called to draw the game_object. When we initalize a basic object, the draw function is automatically set to a simple function that calls the function of the CSFML sfRenderWindowDrawSprite(). So if you only need to draw the object on its own and nothing else, dont touch the draw function. To be able to draw elements in a priority order, every object has a z_index. This index is used when we go trough the object list, we will draw all the object with the biggest z_index, and decrement the index of the loop, so that we draw every object in the good order since CSFML is only 2D.</p>
<pre><font color="red">void</font> draw_objects(<font color="red">game_object_t *</font>object, <font color="red">sfRenderWindow *</font>window, <font color="red">int</font> z_index_max)
{
	<font color="red">game_object_t *</font>tmp = object;<br>
	if (object == NULL)
		<font color="blue">return</font>;
	for (int i = z_index_max; i >= 0;) {
		if (object->texture != NULL && object->z_index == i && object->draw != NULL)
			object->draw(window, object);
		object = object->next;
		if (object == NULL) {
			object = tmp;
			i--;
		}
	}
}</pre>
<p>We will go trough all the object_list to check every object's draw function, if the function isnt null and its the proper z_index, it will call the object's draw function.</p>
<hr>
<h2>Create a draw function</h2>
<p>To use a draw function, you need to take care the arguments are the one needed. As we can see in the game_object structure, the draw function take a <font color="red">sfRenderWindow *</font> and a pointer to the game_object to be drawn. In this exemple we initialize all our game_object_t for the space background, and we set their draw function to &draw_space_background.</p>
<pre><font color="red">game_object_t *</font>rpg_galaxie_generate_space(void)
{
	<font color="red">game_object_t</font> *object = rpg_galaxie_create_ship();
	<font color="red">int</font> x_img_space = 1920 * - 5;
	<font color="red">int</font> y_img_space = 1080 * - 5;<br>
	for (int y = 0, x = 0; y != SIZE_Y_SPACE; x++, x_img_space += 1920) {
		if (x == SIZE_X_SPACE) {
			x_img_space = 1920 * - 5;
			x = 0;
			y++;
			y_img_space += 1080;
		}
		object = create_game_object(object, (char *)BACKGROUND_SPACE, (<font color="red">sfVector2f</font>) {x_img_space, y_img_space}, DECOR);
		object->draw = &draw_space_background;
		if (object == NULL)
			<font color="blue">return</font> (NULL);
	}
	<font color="blue">return</font> (object);
}</pre>
<p>Now that we got our objects created, we create the draw function draw_space_background(). In this exemple, it's usefull to create our own draw function cause we dont want to draw every object of the space. We only want to draw the object's that are on our screen.</p>
<pre><font color="red">void</font> draw_space_background(<font color="red">sfRenderWindow *</font>window, <font color="red">game_object_t *</font>object)
{
	if (object->pos.x > -2880 && object->pos.x < 2880 && object->pos.y > -1620 && object->pos.y < 1620)
		sfRenderWindow_drawSprite(window, object->sprite, NULL);
}</pre>
<p>So to conclude, when the loop will draw every object, thanks to the draw function we created, it will only draw the object's present on our screen.</p>
<h4>Argument of a draw function</h4>
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
			<td>window</td>
			<td>The window on which we draw the object.</td>
			<td><font color="red">sfRenderWindow *</td></font>
		</tr>
		<tr>
			<td>object</td>
			<td>The game_object we got to draw.</td>
			<td><font color="red">game_object_t *</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
