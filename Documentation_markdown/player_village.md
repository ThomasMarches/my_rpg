<h1>Player village</h1>
<p>On this page, we will explain how works the village system.</p>
<hr>
<h2>What is a village concretely ?</h2>
<p>The village is the content of a planet. When you land on it, you arrive on the village. Every planet has a different village.</p>
<hr>
<h2>What does a village contain ? How to create it ?</h2>
<p>Here is an exemple of a way to create a village on a scene thanks to a json file. Just add the proper infos inside the scene's objects_list and it will create and draw it on its own. To create the village, we use the tile mapping.</p>
<pre>"<font color="orange">objects_list</font>": [
	{
		"<font color="purple">type</font>": 18,
		"<font color="purple">map</font>": [
			[6, 0, 6, 0, 6, 0, 6, 0, 0, 12, 0, 11, 0, 0, 0, 12, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 6, 0, 6, 0, 6],
			[5, 5, 0, 5, 0, 5, 0, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0, 0],
			[5, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0],
			[0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 5, 0, 0, 0],
			[5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 5, 0, 0],
			[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0],
			[0, 5, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0],
			[0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0],
			[5, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 0, 0, 5, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
			[0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0]
		],
		"<font color="purple">tile_width</font>": 48,
		"<font color="purple">tile_height</font>": 48
	},
]</pre>
<p>On this table, you can see the value's name in the json file, its usage, and the type of the value. Those are the values you can put inside your json file to create a village.</p>
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
			<td>Always put 18 for a file.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>map</td>
			<td>Contains every tile of the village.</td>
			<td><font color="red">int **</td></font>
		</tr>
		<tr>
			<td>tile_width</td>
			<td>width of a tile.</td>
			<td><font color="red">int</td></font>
		</tr>
		<tr>
			<td>tile_height</td>
			<td>height of a tile.</td>
			<td><font color="red">int</td></font>
		</tr>
	</tbody>
</table>
<hr>
<h2>How does a tile work ?</h2>
<p>The number inside the tile mapping we get, is link to an enum to know what the program has to generate. Then thanks to the number, we get the good sprite_sheet using a static const char *. And finally, using a function's table pointer, we call the proper function.</p>
<pre><font color="red">enum</font> {
	<font color="orange">GRASS</font>,
	<font color="orange">PATH</font>,
	<font color="orange">TAVERN</font>,
	<font color="orange">ARMOR</font>,
	<font color="orange">FOREST1</font>,
	<font color="orange">FOREST2</font>,
	<font color="orange">FOREST3</font>,
	<font color="orange">SHIP</font>,
	<font color="orange">TREE</font>,
	<font color="orange">WEAPON</font>,
	<font color="orange">HOUSE</font>,
	<font color="orange">CASCADE</font>,
	<font color="orange">ROCK</font>,
	<font color="orange">PNJ1</font>,
	<font color="orange">PNJ2</font>,
	<font color="orange">MAX_TILE_ID</font>
};

<font color="purple">static</font> <font color="red">const char *</font>TILE_PATH[] = {
	./sprites_village/grass-tile.png",
	./sprites_village/path.png",
	./sprites_village/tavern.png",
	./sprites_village/armor.png",
	./sprites_village/forest2.png",
	./sprites_village/forest.png",
	./sprites_village/forest3.png",
	./sprites_village/ship.png",
	./sprites_village/tree.png",
	./sprites_village/weapon.png",
	./sprites_village/house.png",
	./sprites_village/cascade.png",
	./sprites_village/rock.png"
};

<font color="purple">static</font> <font color="red">game_object_t *</font>(*TILE_GENERATORS[])(<font color="red">game_object_t *</font>,<font color="red"> sfVector2f</font>, <font color="red">int</font>, <font color="red">int</font>) = {
    &<font color="blue">generate_grass,</font> 
    &<font color="blue">generate_path</font>,
    &<font color="blue">generate_house</font>,
    &<font color="blue">generate_house</font>,
    &<font color="blue">generate_forest</font>,
    &<font color="blue">generate_forest</font>,
    &<font color="blue">generate_forest</font>,
    &<font color="blue">generate_tile</font>,
    &<font color="blue">generate_forest</font>,
    &<font color="blue">generate_house</font>,
    &<font color="blue">generate_house</font>,
    &<font color="blue">generate_waterfall</font>,
    &<font color="blue">generate_tile</font>,
    &<font color="blue">generate_tile</font>,
    &<font color="blue">generate_tile</font>
};</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
