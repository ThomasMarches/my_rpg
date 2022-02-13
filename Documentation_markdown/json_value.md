<h1>Json_value</h1>
<p>On this page, we will explain how works the json_value.</p>
<hr>
<h2>struct json_value_t</h2>
<p>The struct json_value_t contains two things. First of all, a json_value_type to know the type of the value you want to get. And a void pointer that will contain the value.</p>
<pre>typedef struct {
    <font color="red">json_value_type</font> value_type;
    <font color="red">void *</font>value;
} <font color="red">json_value_t</font>;</pre>
<hr>
<h2>Usage exemple</h2>
<p>Here you can see a line that could be inside a json configuration file.</p>
<pre>"<font color="purple">name</font>": "thomas",</pre>
<p>the json_value_type for this exemple would be STRING cause the value "thomas" is a string and the value would be thomas.</p>
<pre>"<font color="purple">age</font>": 19,</pre>
<p>the json_value_type for this exemple would be INT cause the value 19 is an int and the value would be 19.</p>
<hr>
<h2>Json_value_t function</h2>
<pre><font color="red">void</font> json_array_add_value(<font color="red">json_array_t *</font>, <font color="red">json_value_t *</font>value);
<font color="red">void</font> json_value_destroy(<font color="red">json_value_t *</font>js);
<font color="red">json_value_t *</font>json_value_create(<font color="red">void</font>);
<font color="red">json_value_t *</font>json_get_element_by_key(<font color="red">json_object_t *</font>js, <font color="red">char *</font>key);
<font color="red">json_value_t </font>json_parse_get_value(<font color="red">char **</font>buff);
<font color="red">json_value_t </font>json_parse_get_int_value(<font color="red">char **</font>buff);
<font color="red">json_value_t *</font>json_parse_value_array(<font color="red">char **</font>buff);</pre>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
