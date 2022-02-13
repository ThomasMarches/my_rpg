<h1>Planet</h1>
<p>On this page, we will explain how works the planet system.</p>
<hr>
<h2>What is a planet concretely ?</h2>
<p>A planet is a game_object in the galaxy scene with a framekey to animate it. And it's also linked to a button to land on the specific planet.<br>I suggest you to go read constructor's documentation if you want really want to understand how the planet is being initialized thanks to the json file. </p>
<hr>
<h2>What can contain an object inside a scene json_configuration file to create a planet ?</h2>
<p>Here is an exemple of a way to create and draw a planet on the galaxie scene thanks to a json file. Just add the proper infos inside the scene's objects_list and it will draw it on its own. </p>
<pre>"<font color="orange">objects_list</font>": [
	{
		"<font color="purple">type</font>": 10,
		"<font color="purple">name</font>": "planet",
		"<font color="purple">texture_path</font>": "templates/ezgif.com-gif-maker.png",
		"<font color="purple">pos</font>": [-330, -330],
		"<font color="purple">frame_keys</font>": [
			[0, 0, 768, 768]
		]
	},
]</pre>
<p>On this table, you can see the value's name in the json file, its usage, and the type of the value. Those are the values you can put inside your json file to create the planet.</p>
<table>
	<thead>
		<tr>
			<th>Value's key</th>
			<th>Usage</th>
			<th>Type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>type</td>
			<td>Always put 10 for a planet.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>name</td>
			<td>Name of the planet.</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>texture_path</td>
			<td>Filepath to the sprite sheet of your planet.</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>pos</td>
			<td>Position of the planet inside the galaxie.</td>
			<td><font color="red">sfVector2f</td></font>
		</tr>
		<tr>
			<td>frame_keys</td>
			<td>Frame key table to animate the planet ( if you want to ).</td>
			<td><font color="red">sfIntRect **</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>