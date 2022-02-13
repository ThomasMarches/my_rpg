<h1>Item</h1>
<p>On this page, we will explain how works the item handler of our project.</p>
<hr>
<h2>How to create an item</h2>
<p>To create an item, you will need to create and json configuration file in the folder config/item and then to link the file path of the json file inside Include/item/item_path.h. Finally you'll need to add its id to the item_id.h file, here is an exemple.</p>
<h2>Json configuration file</h2>
<pre>{
    <font color="purple">item_id"</font>: 0,
    <font color="purple">item_type"</font>: 0,
    <font color="purple">damage"</font>: 50,
    <font color="purple">name"</font>: "Basic Canoon",
    <font color="purple">description"</font>: "A basic but heavy canoon !",
    <font color="purple">path"</font>: "templates/item.png"
}</pre>
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
			<td>item_id</td>
			<td>Id of your item</td>
			<td><font color="red">item_id</td></font>
		</tr>
		<tr>
			<td>item_type</td>
			<td>Type of the item</td>
			<td><font color="red">item_type</td></font>
		</tr>
		<tr>
			<td>name</td>
			<td>Name of the item</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>description</td>
			<td>Description of the item</td>
			<td><font color="red">char *</td></font>
		</tr>
		<tr>
			<td>Path</td>
			<td>Sprite_path to the item 50x50px image</td>
			<td><font color="red">char *</td></font>
		</tr>
	</tbody>
</table>
<h2>What's an item_id ?</h2>
<p>An item_id is used to make the difference between every item. If you create an item or want to know how it works. Checkout include/item/item_id.h</p>
<pre><font color="green">typedef</font> <font color="red">enum</font> {
	<font color="orange">BASIC_CANON</font>,
	<font color="orange">LASER_CANON</font>,
	<font color="orange">PLASMA_CANON</font>,
	<font color="orange">BASIC_ROCKET</font>,
	<font color="orange">PLASMA_ROCKET</font>,
	<font color="orange">REPAIRING_ITEM</font>,
} <font color="red">item_id</font>;</pre>
<h2>What's an item_type ?</h2>
<p>An item type is used to know whats the use of the item. If it's either a weapon, either an item to repair your ship, either an item gave for a quest.</p>
<pre><font color="green">typedef</font> <font color="red">enum</font> {
	<font color="orange">WEAPON_ITEM</font>,
	<font color="orange">REPAIR_ITEM</font>,
	<font color="orange">QUEST_ITEM</font>,
} <font color="red">item_type</font>;</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
