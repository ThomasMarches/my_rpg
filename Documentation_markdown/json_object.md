<h1>Json_object</h1>
						<p>On this page, we will explain how works the json_object.</p>
						<hr>
				</center>
						<h2>struct json_object</h2>
					<p>The json_object struct contains three components. First of all the key of the value, then, a struct json_value with the value, and to finish a pointer to the next json_object.</p>
					<pre><font color="green">typedef</font> struct<font color="red"> json_object</font> {
    <font color="red">char</font> *key;
    <font color="red">json_value_t</font> value;
    <font color="red">struct json_object *</font>next;
} <font color="red">json_object_t</font>;</pre>
<hr>
<h2>Usage exemple</h2>
<p>Here you can see an exemple of a json_object inside a json configuration file.</p>
<pre>{
	"<font color="purple">name</font>": "thomas",
	"<font color="purple">age</font>": 19,
	"<font color="purple">alive</font>": true,
}</pre>
<p>In this exemple, the json_objects would contain:</p>
<table>
	<thead>
		<tr>
			<th></th>
			<th>key</th>
			<th>json_value</th>
			<th>json_value_type</th>
			<th>next</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>json_object 1</td>
			<td>"name"</td>
			<td>thomas</td>
			<td><font color="orange">STRING</font></td>
			<td>Pointer to json_object 2</td>
		</tr>
		<tr>
			<td>json_object 2</td>
			<td>"age"</td>
			<td>19</td>
			<td><font color="orange">INT</font></td>
			<td>Pointer to json_object 3</td>
		</tr>
		<tr>
			<td>json_object 3</td>
			<td>"alive"</td>
			<td>true</td>
			<td><font color="orange">BOOLEAN</font></td>
			<td><font color="red">NULL</font></td>
		</tr>
	</tbody>
</table>
<hr>
<h2>json_object function</h2>
<pre><font color="red">json_object_t *</font>json_object_create(<font color="red">void</font>);
<font color="red">json_object_t *</font>json_create_from_string(<font color="red">char *</font>buff);
<font color="red">json_object_t *</font>json_create_from_fd(<font color="red">int </font>fd);
<font color="red">json_object_t *</font>json_create_from_file(<font color="red">char *</font>path);
<font color="red">void</font> json_object_destroy(<font color="red">json_object_t *</font>js);
<font color="red">json_object_t *</font>json_parse_object(<font color="red">char **</font>buff);
</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
