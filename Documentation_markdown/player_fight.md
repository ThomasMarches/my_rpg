<h1>Player fight</h1>
<p>On this page, we will explain how works the player fighting system.</p>
<hr>
<h3>Json configuration file of a fight scene.</h3>
<p>If you've read the quest and the ennemy documentation, you know how to make a quest and init an ennemy inside a json_config file.</p>
<hr>
<h3>What does a fight_scene json configuration looks like ?</h3>
<p>The important game_objects for the fight are here.</p>
<pre>"<font color="orange">objects_list</font>": [
	{
		"<font color="red">type</font>": 13
	},
	{
		"<font color="red">type</font>": 14
	},
	{
		"<font color="red">type</font>": 15
	}
]</pre>
<p>On this table, you can see the three important game_objects and the component they're linked to.</p>
<table>
	<thead>
		<tr>
			<th>Type</th>
			<th>Component</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>13</td>
			<td>Ennemy ( will get the stats from the quest ).</td>
		</tr>
		<tr>
			<td>14</td>
			<td>Spaceship ( will get the stats from the game ).</td>
		</tr>
		<tr>
			<td>15</td>
			<td>Fight handler ( game_object handling all the fighting system ).</td>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2>
