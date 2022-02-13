<h1>Json_constructors</h1>
<p>On this page, we will explain how we created a constructor using json and the lib my_game.</p>
<hr>
<h2>A mix of the lib my_game and the json_parser.</h2>
<p>We decided to use the json parser and my_game lib to create a system that will initialize automatically game_objects using the json_file. Which means inside your code, you dont need to call a function that initalize a game_object, if you follow the given exemples of this page, the object will be created thanks to a json file..</p>
<hr>
<h2>Game_object exemple inside a json file.</h2>
<p>Here you can see an exemple of object used inside the object_list of a scene.</p>
<pre><font color="orange">"objects_list"</font>: [
	{
		<font color="red">"type"</font>: 0,
		<font color="red">"string"</font>: "How to play",
		<font color="red">"font"</font>: "templates/font/space.ttf",
		<font color="red">"pos"</font>: [400, 100],
		<font color="red">"style"</font>: 0,
		<font color="red">"size"</font>: 100
	}
]</pre>
<p>In this exemple, we initializing a text using the text_handler. But what's behind this?</p>
<hr>
<h2>Constructors file.</h2>
<p>Let's head to the constructors.h file and analyse whats inside. We can see three components. The enum, the protype of the different functions, and the function's pointer table. Lets keep only the text_handler components and analyse how it works.</p>
<pre><font color="red">enum</font> {
	<font color="orange">TEXT_HANDLER_CONSTRUCTOR</font>,
	<font color="orange">CONSTRUCTORS_MAX_ID</font>
};<br><br>
<font color="red">game_object_t *</font>rpg_create_text_handler_from_conf(<font color="red">game_object_t *</font>last, <font color="red">json_object_t *</font>js, <font color="red">game_t *</font>game, <font color="red">scene_t *</font>scene);
<br>
<font color="purple">static</font> <font color="red">game_object_t *</font>(*CONSTRUCTORS[])(<font color="red">game_object_t *</font>, <font color="red">json_object_t *</font>, <font color="red">game_t *</font>, <font color="red">scene_t *</font>) = {<br>	&<font color="blue">rpg_create_text_handler_from_conf</font>
};</pre>
<p>Okay how does all of this work together? It's simple. <br><br>Inside our json file, there's a line written <b>"type": 0,</b>. This line is linked to the enum of constructors.h. And the function's point table is also linked to the enum.<br>So in this exemple, our library will parse the json file, get the object_lists of it, parse it, and see that the first object is of type "0". So it's gonna check inside the CONSTRUCTORS table whats the function at the index 0, and it will call it sending the json_object containing all the informations of the object.</p>
<hr>
<h2>Create my own constructors and game_object.</h2>
<p>Let's now imagine you want to create game_object containing the informations you want and you also want to link it to the json_parser.</p>
<ul>
<li>The first step is adding an index to the enum of constructors.h, create a function taking the same argument as <b>rpg_create_text_handler_from_conf</b> that we've seen before, and adding its prototypes to the .h file.</li>
<br><li>The second step is moduling your object and your object->extend using the json_get functions to get any informations you need from the json file and put them inside your extend structure or your game_object structure.</li>
<br><li>The third step is heading to game_object.h and add the game_object_type if it's needed.</li>
<br><li>The fourth step is creating the callback, update, and draw functions if your game_object needs a particular one.</li>
</ul><br>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
