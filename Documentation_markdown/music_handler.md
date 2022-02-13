<h1>Music_handler</h1>
<p>On this page, we will explain how works music_handler component.</p>
<hr>
<h2>What is a music_handler ?</h2>
<p>A music_handler is a component that allow you to play a music on each scene thanks to a json configuration file.<br>I suggest you to go read constructor's documentation</a> if you want really want to understand how the music is being initialized thanks to the json file. </p>
<hr>
<h2>What can contain an object inside a scene json_configuration file to create a music ?</h2>
<p>Here is an exemple of a way to create a music on a scene thanks to a json file. Just add the proper infos inside the scene's objects_list and it will play the music on its own. </p>
<pre>"<font color="orange">objects_list</font>": [
    {
        "<font color="purple">type</font>": 15,
        "<font color="purple">loop</font>": 1,
        "<font color="purple">volume</font>": 100,
        "<font color="purple">sound_path</font>": "templates/sounds/exemple.ogg"
    },</pre>
<p>On this table, you can see the value's name in the json file, its usage, and the type of the value. Those are the values you can put inside your json file to create a text.</p>
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
            <td>Always put 15 for a music.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>loop</td>
            <td>Put 1 if you want the music to loop, 0 if not.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>volume</td>
            <td>Volume from 0 to 100.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>sound_path</td>
            <td>Filepath to the music file.</td>
            <td><font color="red">char *</td></font>
        </tr>
    </tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
