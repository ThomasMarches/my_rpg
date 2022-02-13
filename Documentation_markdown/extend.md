<h1>Extend of a game_object</h1>
<p>On this page, we will explain the extend of a game_object and how it works.</p>
<hr>
<h2>What is an extend ?</h2>
<p>As you can see on the struct game_object , there is a <font color="red">void *</font>extend and a <font color="red">void</font> (*free_extend)(<font color="red">void *</font>). The extend is a void pointer. Its used to link any kind of struct to our game_object to make it as generic as possible. Different kind of objects can need things that we didnt put in the struct to make it smoother. For exemple a spaceship would need hp, a npc would need a name, etc, etc... The free_extend is simply a function that we call to free the extend of the object.</p>
<h2>Exemple of extend</h2>
<pre><font color="green">typedef</font> struct <font color="red">shop</font> {
	<font color="red">char *</font>name;
	<font color="red">char **</font>item_name;
	<font color="red">char **</font>item_description;
	<font color="red">int *</font>item_price;
	<font color="red">int *</font>item_id;
	<font color="red">sfVector2f **</font>item_pos;
	<font color="red">sfIntRect **</font>item_rect;
	<font color="red">int </font>number_of_items;
	<font color="red">void</font> (*free_shop)(<font color="red">void *</font>);
} <font color="red">shop_t</font>;</pre>
<p>Here you can see the struct shop_t. Let's imagine we want to create a game_object_t *shop. We will need things that arent inside a basic game_object. So we will use the void *extend to point on the a shop_t *.</p>
<h2>Create the shop</h2>
<p>Lets create a game_object_t *shop and use the extend to point on a shop_t *.</p>
<pre><font color="red">game_object_t *</font>rpg_shop_create(<font color="red">game_object_t *</font>last, <font color="red">char *</font>sprite_path, <font color="red">char *</font>settings_path)
{
	<font color="red">game_object_t *</font>object = create_game_object(last, sprite_path, (<font color="red">sfVector2f</font>) {0, 0}, SHOP);<br>
	if (object == NULL)
		<font color="blue">return</font> (NULL);
	object->extend = (<font color="red">shop_t *</font>) rpg_init_shop(settings_path);
	if ((<font color="red">shop_t *</font>) object->extend == NULL)
		<font color="blue">return</font> (NULL);
	<font color="blue">return</font> (object);
}</pre>
				<p>As you can see, we cast the extend a (shop_t *) and we call the function rpg_init_shop().</p>
				<h2>Init the extend.</h4>
				<p>Let's now create the function rpg_init_shop() to init the value of our extend..</p>
				<pre><font color="red">shop_t *</font>rpg_init_shop(<font color="red">char *</font>path)
{
	<font color="red">shop_t *</font>shop = malloc(sizeof(<font color="red">shop_t</font>));<br>
	if (shop == NULL)
		<font color="blue">return </font>(NULL);
	//HERE YOU CAN INITIALIZE EVERY VALUE OF A STRUCT SHOP
	<font color="blue">return</font> (shop);
}</pre>
<p>Don't forget everytime you'll want to acess the value of your extend, you will have to cast again like we did in the function rpg_shop_create().</p>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
