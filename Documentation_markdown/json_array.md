<h1>Json_array</h1>
<p>On this page, we will explain how works the json_array.</p>
<hr>
<h2>struct json_array_t</h2>
<p>The struct json_array contains two components. First of all, the number of element it contains and then, a table of <a href="json_value.html">json_value_t</a> with all the value of a component.</p>
<pre>typedef struct {
    <font color="red">int</font> elem_count;
    <font color="red">json_value_t **</font>array;
} <font color="red">json_array_t</font>;</pre>
<hr>
<h2>Usage exemple</h2>
<p>Here you can see an exemple of a json_array_t inside a json configuration file.</p>
<pre>"<font color="orange">scene</font>": {
	"<font color="purple">id</font>": 0,
	"<font color="purple">z_index_deepth</font>": 0,
	"<font color="purple">draw_id</font>": 0,
	"<font color="purple">update_id</font>": 0,
	"<font color="purple">events_ids</font>": [
		[0, 0],
		[1, 9]
	],
	"<font color="purple">background_color</font>": [0, 0, 0, 0]
}</pre>
<p>In this exemple, the json_array values would be: <br>elem_count: 6</p>
<table>
	<thead>
		<tr>
			<th>array number</th>
			<th>json_value</th>
			<th>json_value_type</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>0</td>
			<td><font color="orange">INT</font></td>
		</tr>
		<tr>
			<td>1</td>
			<td>0</td>
			<td><font color="orange">INT</font></td>
		</tr>
		<tr>
			<td>2</td>
			<td>0</td>
			<td><font color="orange">INT</font></td>
		</tr>
		<tr>
			<td>3</td>
			<td>0</td>
			<td><font color="orange">INT</font></td>
		</tr>								
		<tr>
			<td>4</td>
			<td>{0, 0}, {1, 9}</td>
			<td><font color="orange">ARRAY</font></td>
		</tr>								
		<tr>
			<td>5</td>
			<td>{0, 0, 0, 0}</td>
			<td><font color="orange">ARRAY</font></td>
		</tr>
	</tbody>
</table>
<hr>
<h2>Json_array_t function</h2>
<pre><font color ="red">json_array_t *</font>json_array_create(<font color="red">void</font>);
<font color ="red">void</font> json_array_add_value(<font color="red">json_array_t *</font>, <font color="red">json_value_t *</font>value);
<font color ="red">json_array_t *</font>json_parse_array(<font color="red">char **</font>buff);
<font color ="red">void</font> json_array_destroy(<font color="red">json_array_t *</font>array);</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
