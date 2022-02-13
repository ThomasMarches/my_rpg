<h1>NPC</h1>
<p>On this page, we will explain how works a npc and its dialog.</p>
<hr>
<h2>Exemple of a NPC inside a scene json configuration file.</h2>
<p>To create a NPC, you will need to initialize its object inside the scene json configuration file of the scene and you will also need to create a json file of the npc and put all the information about the dialog and the type of NPC.</p>
<h2>Json file of the scene</h2>
<pre> "<font color="orange">objects_list</font>": [
	{
		"<font color="purple">type</font>": 18,
		"<font color="purple">json_path</font>": "config/PNJ/pnj.json",
		"<font color="purple">texture_path</font>": "templates/item.png",
		"<font color="purple">pos</font>": [500, 500]
	}
]</pre>
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
			<td>Always put 18 for a NPC.</td>
			<td><font color="red">int</font></td>
		</tr>
		<tr>
			<td>json_path</td>
			<td>Path to the JSON configuration file of the NPC.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>texture_path</td>
			<td>Path to the sprite_sheet of the NPC.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>pos</td>
			<td>The position of the NPC.</td>
			<td><font color="red">sfVector2f</font></td>
		</tr>
	</tbody>
</table>
<h2>Json file of the NPC ( QUEST NPC )</h2>
<pre>{
	"<font color="green">pnj</font>": {
		"<font color="orange">id</font>": 0,
		"<font color="orange">type</font>": 0,
		"<font color="orange">name</font>": "Dark Vador",
		"<font color="orange">quest</font>": 0,
		"<font color="orange">dialog</font>": [
			{
				"<font color="purple">type</font>": 0,
				"<font color="purple">speaker</font>": 0,
				"<font color="purple">message</font>": " : Okay i will check this, thank you !"
			},
			{
				"<font color="purple">type</font>": 0,
				"<font color="purple">speaker</font>": 1,
				"<font color="purple">message</font>": " : Hello, yes i've heard people saw your friend getting into a ship going at Khalus"
			},
			{
				"<font color="purple">type</font>": 0,
				"<font color="purple">speaker</font>": 0,
				"<font color="purple">message</font>": " : Hello, did you hear anything about the disapear of Caus ?"
			},
			{
				"<font color="purple">type</font>": 0,
				"<font color="purple">speaker</font>": 1,
				"<font color="purple">message</font>": " : Hello, what can i do for you ?"
			},
			{
				"<font color="purple">type</font>": 1,
				"<font color="purple">speaker</font>": 1,
				"<font color="purple">message</font>": " : You've completed the quest ! Congratulations !"
			},  
			{
				"<font color="purple">type</font>": 2,
				"<font color="purple">speaker</font>": 1,
				"<font color="purple">message</font>": " : How is the quest going ?"
			}
		]
	}
}</pre>
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
			<td>id</td>
			<td>pnj_id ( refer to pnj.h )</td>
			<td><font color="red">pnj_id</font></td>
		</tr>
		<tr>
			<td>type</td>
			<td>Type of the NPC ( Quest, shop, dialog ).</td>
			<td><font color="red">pnj_type</font></td>
		</tr>
		<tr>
			<td>name</td>
			<td>Name of the NPC.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>quest</td>
			<td>id of the quest related to the NPC ( only for quest NPC ).</td>
			<td><font color="red">quest_id</font></td>
		</tr>
		<tr>
			<td>dialog</td>
			<td>Contains every step of the NPC's dialog.</td>
			<td><font color="red">array</font></td>
		</tr>
	</tbody>
</table>
<h2>Dialog informations</h2>
<p>When you create the dialog of type 0, always write them in the inversed sense. So the first message at the end of the dialog_list and the last message at the top. </p>
<ul>
	<li><b>type :</b> The type definds the usage of the message. 0 is the dialog the player will see when he gets the quest. 1 is the message he will see when he will talk to the NPC if he's doing his quest and 2 is the message the NPC will show when he gives back the quest. If you create a dialog NPC, leave every type to 0.</li>
	<br><li><b>speaker : </b> 1 means the NPC is talking and 0 means the player is talking.</li>
	<br><li><b>message : </b> Contains the message that will be written.</li>
</ul>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
