<h1>Player spaceship</h1>
<p>On this page, we will explain how works the player spaceship component.</p>
<hr>
<h2>What is the player spaceship component ?</h2>
<p>The player spaceship component is the spaceship that the player is moving inside the galaxie using the mouse-click.</p>
<hr>
<h2>What can contain an object inside a scene json_configuration file to create the spaceship ?</h2>
<pre>"<font color="orange">objects_list</font>": [
{
	"<font color="red">type</font>": 8,
	"<font color="red">texture_path</font>": "templates/menu/ship1.png",
	"<font color="red">pos</font>": [890, 399],
	"<font color="red">box</font>": [890, 399, 200, 202]
}</pre>
<p>On this table, you can see the value's name in the json file, its usage, and the type of the value. Those are the values you can put inside your json file to create a text.</p>
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
			<td>Always put 8 for the spaceship.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>texture_path</td>
			<td>Spritesheet to the spaceship..</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>pos</td>
			<td>Position of the spaceship on your window.</td>
			<td><font color="red">sfVector2f</td></font>
		</tr>
		<tr>								
			<td>box</td>
			<td>box of the sprite.</td>
			<td><font color="red">sfIntRect</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h1>Go back to the heading documentation page</h1></a>
