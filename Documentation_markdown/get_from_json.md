<h1>Get from json function</h1>
<p>On this page we will show you the different get_functions we already created to get infos from a json_file.</p>
<hr>
<h2>get_color_from_conf</h2>
<p>This function is used to get a <font color="red">sfColor</font> from a json file.</p>
<pre><font color="red">bool</font> get_color_from_conf(<font color="red">json_object_t *</font>js, <font color="red">sfColor *</font>color, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t</font></td>
		</tr>
		<tr>
			<td>color</td>
			<td>Pointer on the sfColor you want to initalize.</td>
			<td><font color="red">sfColor *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">true</font> if it found the sfColor and return <font color="red">false</font> if it didnt.</p>
<hr>
<h2>get_frame_keys_from_conf</h2>
<p>This function is used to get a <font color="red">sfIntRect **</font> from a json file if you want to animate an object for exemple.</p>
<pre><font color="red">sfIntRect **</font>get_frame_keys_from_conf(<font color="red">json_object_t *</font>js, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">NULL</font> if it didnt find anything and will return the <font color="red">sfIntRect **</font> of the json_file if it found it.</p>
<hr>
<h2>get_int_from_conf</h2>
<p>This function is used to get an <font color="red">int</font> from a json file if you want to get for exemple an enum value, or any value that is a number (hp, shield, etc..).</p>
<pre><font color="red">bool</font> get_int_from_conf(<font color="red">json_object_t *</font>js, <font color="red">int *</font>var, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t *</font></td>
		</tr>
		<tr>
			<td>var</td>
			<td>Pointer on the int you want to initalize.</td>
			<td><font color="red">int *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">false</font> if it didnt find the int and will return <font color="red">true</font> if it found it.</p>
<hr>
<h2>get_intrect_from_conf</h2>
<p>This function is used to get a <font color="red">sfIntRect *</font> from a json file if you want to get for exemple a box.</p>
<pre><font color="red">bool</font> get_intrect_from_conf(<font color="red">json_object_t *m</font>js, <font color="red">sfIntRect *</font>rect, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t *</font></td>
		</tr>
		<tr>
			<td>rect</td>
			<td>Pointer on the sfIntRect you want to initalize.</td>
			<td><font color="red">sfIntRect *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">false</font> if it didnt find the int and will return <font color="red">true</font> if it found it.</p>
<hr>
<h2>get_str_from_conf</h2>
<p>This function is used to get a <font color="red">char *</font> from a json file if you want to get a file_path for exemple.</p>
<pre><font color="red">char *</font>get_str_from_conf(<font color="red">json_object_t *</font>js, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">NULL</font> if it didnt find anything and will return the <font color="red">char *</font> of the json_file if it found it.</p>
<hr>
<h2>get_vector2f_from_conf</h2>
<p>This function is used to get a <font color="red">sfVector2f</font> from a json file if you want to get for exemple a position or a move vector.</p>
<pre><font color="red">bool</font> get_vector2f_from_conf(<font color="red">json_object_t *</font>js, <font color="red">sfVector2f *</font>pos, <font color="red">char *</font>key)</pre>
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
			<td>js</td>
			<td>Json_object ( contains all the json settings of an object ).</td>
			<td><font color="red">Json_object_t *</font></td>
		</tr>
		<tr>
			<td>pos</td>
			<td>Pointer on the sfVector2f you want to initalize.</td>
			<td><font color="red">sfVector2f *</font></td>
		</tr>
		<tr>
			<td>key</td>
			<td>The name of the setting you put inside the json file.</td>
			<td><font color="red">char *</font></td>
		</tr>
	</tbody>
</table>
<p>The function will return <font color="red">false</font> if it didnt find the int and will return <font color="red">true</font> if it found it.</p>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
