<h1>Quest</h1>
<p>On this page, we will explain how works the quest system.</p>
<hr class="major">
<h2>Exemple of a quest inside a Json_file.</h2>
<p>You will need to initialize the informations about the quest and then the informations about every step of the quest one by one. It's important that you put the step in an inversed order, so from the last step to the first step.</p>
<pre>{
	<font color="green">"quest"</font>: {
		<font color="orange">"id"</font>: 0,
		<font color="orange">"name"</font>: "Exemple de quete",
		<font color="orange">"number_of_step"</font>: 3,
		<font color="orange">"reward_item"</font>: 1,
		<font color="orange">"reward_item_number"</font>: 1,
		<font color="orange">"reward_money"</font>: 100,
		<font color="orange">"step_list"</font>: [
			{
				<font color="purple">"type"</font>: 0,
				<font color="purple">"validated"</font>: 0,
				<font color="purple">"step_number"</font>: 3,
				<font color="purple">"description"</font>: "Speak back with Dark Vador and show him what you've found on ValDrus.",
				<font color="purple">"pos"</font>: [1000, 3000]
			},
			{
				<font color="purple">"type"</font>: 1,
				<font color="purple">"validated"</font>: 0,
				<font color="purple">"step_number"</font>: 2,
				<font color="purple">"description"</font>: "Fight with ValDrus and see if he has any paper on his body !",
				<font color="purple">"pos"</font>: [1000, 2000],
				<font color="purple">"fight_scene"</font>: "config/fight_scene.json"
			},
			{
				<font color="purple">"type"</font>: 2,
				<font color="purple">"validated"</font>: 0,
				<font color="purple">"step_number"</font>: 1,
				<font color="purple">"description"</font>: "Head to 1000, 2000 in the galaxie to reach ValDrus's place.",
				<font color="purple">"scene"</font>: 5,
				<font color="purple">"pos"</font>: [1000, 2000]
			}
		]
	}
}</pre>
<h2>Quest informations.</h2>
<table>
	<thead>
		<tr>
			<th>Argument's name</th>
			<th>Usage</th>
			<th>Type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>id</td>
			<td>quest_id of the quest.</td>
			<td><font color="red">quest_id</font></td>
		</tr>
		<tr>
			<td>name</td>
			<td>Name of the quest.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>number_of_step</td>
			<td>Number of step of the quest.</td>
			<td><font color="red">int</font></td>
		</tr>
		<tr>
			<td>reward_item</td>
			<td>The item_id of the item the quest gives as a reward.</td>
			<td><font color="red">item_id</font></td>
		</tr>
		<tr>
			<td>reward_item_number</td>
			<td>Number of time you'll get the reward_item</td>
			<td><font color="red">int</font></td>
		</tr>
		<tr>
			<td>step_list</td>
			<td>Contains all the steps of the quest.</td>
			<td><font color="red">array</font></td>
		</tr>
	</tbody>
</table>
<h2>step_list informations.</h2>
<table>
	<thead>
		<tr>
			<th>Argument's name</th>
			<th>Usage</th>
			<th>Type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>type</td>
			<td>Type of the step ( FIGHT / REACH / DIALOG )</td>
			<td><font color="red">step_type</font></td>
		</tr>
		<tr>
			<td>validated</td>
			<td>Used to know if the step has to be automatically validated.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>step_number</td>
			<td>Number of the step.</td>
			<td><font color="red">int</font></td>
		</tr>
		<tr>
			<td>description</td>
			<td>Description of the step.</td>
			<td><font color="red">char *</font></td>
		</tr>
		<tr>
			<td>pos</td>
			<td>Position where the player has to go to achieve the step.</td>
			<td><font color="red">sfVector2f</font></td>
		</tr>
		<tr>
			<td>fight_scene</td>
			<td>Filepath to the json configuration of the fight_scene. (NEEDED ONLY FOR FIGHT STEP_TYPE)</td>
			<td><font color="red">array</font></td>
		</tr>
		<tr>
			<td>scene</td>
			<td>scene where the player has to be to achieve a step. (NEEDED ONLY FOR REACH STEP_TYPE)</td>
			<td><font color="red">scene_index</font></td>
		</tr>
	</tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
