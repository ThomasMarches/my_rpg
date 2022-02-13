<h1>Json_value_type</h1>
<p>On this page, we will explain how works the json_value_type.</p>
<hr>
<h2>enum json_value_type</h2>
<pre><font color="green">typedef</font> <font color="red">enum</font> {
    <font color="orange">NONE</font>,
    <font color="orange">BOOLEAN</font>,
    <font color="orange">INT</font>,
    <font color="orange">STRING</font>,
    <font color="orange">OBJECT</font>,
    <font color="orange">ARRAY</font>
} <font color="red">json_value_type;</font></pre>
<p>The json_value_type is the type of value you're getting from the json file. Dont use NONE.</p>
<hr>
<h2>Usage exemple</h2>
<p>Here you can see a line that could be inside a json configuration file.</p>
<pre>"<font color="purple">name</font>": "thomas",</pre>
<p>the json_value_type for this exemple would be STRING cause the value "thomas" is a string.</p>
<pre>"<font color="purple">age</font>": 19,</pre>
<p>the json_value_type for this exemple would be INT cause the value 19 is an int.</p>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
