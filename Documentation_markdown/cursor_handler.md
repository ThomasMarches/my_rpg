<h1>Cursor_handler</h1>
<p>On this page, we will explain how works the cursor handler.</p>
<hr>
<h2>What is a cursor_handler ?</h2>
<p>The cursor handler is a component that allow you creating and having a different cursor on each scene thanks to a json configuration file.<br>I suggest you to go read constructor's documentation if you want really want to understand how the cursor is being initialized thanks to the json file. </p>
<hr>
<h2>What can contain an object inside a scene json_configuration file to create a cursor ?</h2>
<p>Here is an exemple of a way to create a cursor on a scene thanks to a json file. Just add the proper infos inside the scene's objects_list and it will draw the cursor at the good position on its own. </p>
<pre>"<font color="orange">objects_list</font>": [
	{
		"<font color="purple">type</font>": 19,
		"<font color="purple">texture_path</font>": "templates/menu/cursor.png"
	}
]</pre>
<p>On this table, you can see the value's name in the json file, its usage, and the type of the value. Those are the values you can put inside your json file to create a cursor.</p>
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
			<td>Always put 19 for a cursor.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>texture_path</td>
			<td>Filepath to the image of the cursor.</td>
			<td><font color="red">char *</td></font>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
