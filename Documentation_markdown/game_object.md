<h1>Game_object</h1>
<p>On this page, we will explain what is a game_object and how it works.</p>
<hr>
<h2>What is a game_object ?</h2>
<p>A game_object is a structure that has to be as generic as possible so you can use the same struct for every object of your program.</p>
<pre><font color="green">typedef</font> struct <font color="red">game_object</font>
{
	<font color="red">sfTexture *</font>texture;                                   		/**< Texture of the object*/
	<font color="red">sfSprite *</font>sprite;                                     		/**< Sprite of the object*/
	<font color="red">sfColor </font>sprite_color;                                 		/**< Color of the sprite used from fade in/out*/
	<font color="red">sfSound *</font>sound_effect;                                		/**< Sound player*/
	<font color="red">sfVector2f </font>pos;                                       		/**< Vector of the position of the object*/
	<font color="red">sfVector2f </font>last_pos;                                  		/**< Vector of the previous position of the object after a move*/
	<font color="red">int</font> z_index;                                          		/**< Index used to display order in scene*/
	<font color="red">sfIntRect</font> box;                                        		/**< Box of the object*/
	<font color="red">sfVector2f</font> move;                                      		/**< Vector of the move of the object*/
	<font color="red">anim_t *</font>anim;                                         		/**< Table of animations for the object*/
	<font color="red">int</font> state;                                             		/**< State of the object*/
	<font color="red">object_type</font> type;                                      		/**< Type of the object*/
	<font color="red">sfClock *</font>delta_t;                                      		/**< Local clock of the object*/
	<font color="red">bool</font> (*update)(struct<font color="red">  game_object_t *</font>, struct<font color="red"> scene *</font>); 	/**< Update function of the object*/
	<font color="red">void</font> (*callback)(struct<font color="red">  game_object_t *</font>, <font color="red">void *</font>);       	/**< Callback function of the object*/
	<font color="red">void</font> (*draw)(<font color="red">sfRenderWindow *</font>, struct<font color="red">  game_object_t *</font>); 	/**< Draw function of the object*/
	<font color="red">struct  game_object_t *</font>next;                             	/**< Next object in the list*/
	<font color="red">void *</font>extend;                                         		/**< extend other attributes*/
	<font color="red">void</font> (*free_extend)(<font color="red">void *</font>);					/**< Function to free the game_object extend*/
} <font color="red">game_object_t</font>;</pre>
<p>If you want to learn more about the callback, update, and draw function, or how an extend works, head to the specific documentation page.</p>
<hr>
<h2>Create a game_object</h2>
<p>Let's imagine you now want to crate you own game_object. There are two ways of doing it. Either calling the function create_game_object(), either head to the constructors page and use the json_parser to create easily powerfull objects.</p>
<h4>Create_game_object</h4>
<pre><font color="red">game_object_t *</font>create_game_object(<font color="red">game_object_t *</font>last, <font color="red">char *</font>sprite_path, <font color="red">sfVector2f</font> pos, <font color="red">object_type</font> type)
{
	<font color="red">game_object_t *</font>object = malloc(sizeof(<font color="red">game_object_t</font>));<br>
	if (object == NULL)
		<font color="blue">return</font> (NULL);
	init_game_object(object);
	object->sprite = sfSprite_create();
	object->texture = sfTexture_createFromFile(sprite_path, NULL);
	if (object->sprite == NULL || object->texture == NULL)
		<font color="blue">return</font> (NULL);
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->pos = pos;
	object->type = type;
	object->next = last;
	sfSprite_setPosition(object->sprite, object->pos);
	<font color="blue">return</font> (object);
}</pre>
<p>The init_game_object function will initailize every value of the game_object to NULL. It will also set the draw function to the basic one we created. So after creating an object, it will automatically draw it if you didnt set the draw function to NULL or change it.</p>
<h4>Argument of the function create_game_object().</h4>
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
			<td>last</td>
			<td>Head of the linked list</td>
			<td><font color="red">game_object_t *</td></font>
		</tr>
		<tr>
			<td>Sprite_path</td>
			<td>Filepath to the sprite sheet of the object</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>Pos</td>
			<td>Position vector of the object</td>
			<td><font color="red">sfVector2f</td></font>
		</tr>
		<tr>
			<td>type</td>
			<td>Type of the object</td>
			<td><font color="red">object_type</td></font>
		</tr>
	</tbody>
</table>
<h2>Object_type</h2>
<p>Here you will see the enum of the object_type, it's used to know what is the object you're actually on while you go trough your object_list.</p>
<pre><font color="green">typedef</font> <font color="red">enum</font>
{
	<font color="orange">TOWER</font>,
	<font color="orange">BUTTON</font>,
	<font color="orange">TEXT_BUTTON</font>,
	<font color="orange">BAR</font>,
	<font color="orange">DECOR</font>,
	<font color="orange">EFFECT</font>,
	<font color="orange">FLEUR</font>,
	<font color="orange">INFO</font>,
	<font color="orange">SHOP</font>,
	<font color="orange">ENNEMY</font>,
	<font color="orange">GROUND</font>,
	<font color="orange">GRASS</font>,
	<font color="orange">npc</font>,
	<font color="orange">ROCK</font>,
	<font color="orange">UPGRADE_BUTTON</font>,
	<font color="orange">SPACESHIP</font>,
} <font color="red">object_type</font>;</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
