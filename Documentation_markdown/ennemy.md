<h1>Ennemy</h1>
<p>On this page, we will explain how works the ennemy system.</p>
<hr>
<h2>What is an ennemy concretely ?</h2>
<p>An ennemy is an entity ( a game_object ) that you will fight during a fight_scene. The ennemy is initailized in the json_file of the fight scene and the path of the json file is inside the json file of a quest.<br>I suggest you to go read constructor's documentation if you want really want to understand how the ennemy is being initialized thanks to the json file.</p>
<hr>
<h2>Ennemy structure</h2>
<pre><font color="green">typedef</font> struct <font color="red">ennemy</font> {
    <font color="red">char *</font>name;
    <font color="red">int </font>hp;
    <font color="red">int </font>max_hp;
    <font color="red">int </font>shield;
    <font color="red">int </font>action_number;
    <font color="red">int </font>dodge_value;
    <font color="red">int </font>repair_value;
    <font color="red">item_id </font>equiped_weapon;
    <font color="red">int </font>damage;
    <font color="red">bool </font>in_fight;
    <font color="red">action_id *</font>id;
    <font color="red">int </font>repair_statue;
    <font color="red">sfText *</font>name_text;
    <font color="red">sfText *</font>hp_text;
    <font color="red">sfText *</font>shield_text;
} <font color="red">ennemy_t</font>;</pre>
<table>
    <thead>
        <tr>
            <th>Value's name</th>
            <th>Usage</th>
            <th>type</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>name</td>
            <td>Contains the ennemy's name.</td>
            <td><font color="red">char *</td></font>
        </tr>
        <tr>
            <td>hp</td>
            <td>Contains the ennemy's hp.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>max_hp</td>
            <td>Contains the ennemy's max hp.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>shield</td>
            <td>Contains the ennemy's shield.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>action_number</td>
            <td>Contains the number of actions the ennemy can make every turn.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>dodge_value</td>
            <td>The value to know how many times he decided to dodge in a given turn.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>repair_value</td>
            <td>Value to know how much he's going to heal everytime he does a repair action.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>equiped_weapon</td>
            <td>Contains the ennemy's equiped weapon.</td>
            <td><font color="red">item_id</td></font>
        </tr>
        <tr>
            <td>damage</td>
            <td>Contains the ennemy's damage of each attack.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>in_fight</td>
            <td>Boolean to know if the fight is on.</td>
            <td><font color="red">boolean</td></font>
        </tr>
        <tr>
            <td>id</td>
            <td>Table of actions that contains the ennemy's actions of every turn</td>
            <td><font color="red">action_id *</td></font>
        </tr>
        <tr>
            <td>repair_statue</td>
            <td>This value is to know if the ennemy is able to repair this turn or not.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>name_text</td>
            <td>Text drawing the name of the ennemy on the fighting board.</td>
            <td><font color="red">sfText *</td></font>
        </tr>
        <tr>
            <td>hp_text</td>
            <td>Text drawing the life of the ennemy on the fighting board.</td>
            <td><font color="red">sfText *</td></font>
        </tr>
        <tr>
            <td>shield_text</td>
            <td>Text drawing the shield of the ennemy on the fighting board.</td>
            <td><font color="red">sfText *</td></font>
        </tr>
    </tbody>
</table>
</div>
<hr>
<h2>How to create an ennemy.</h2>
<p>Okay now let's imagine you want to create a fight. You will first need to initialize a quest and to put the json configuration file of your fight_scene containing the ennemy inside one of the quest step.</p>
 <h2>Exemple of creating an ennemy.</h2>
<p>Let's imagine you've gone to the >quest's documentation and you've created a whole quest. Now you want to create the ennemy of a fight_scene. So you will create the json file of the fight_scene and you will want to init an ennemy. Don't forget to checkout the documentation of the fight_scene and the quest to be sure you dont forget anything on your scene.</p>
<pre>{
    "<font color="purple">opponent</font>": {
        "<font color="orange">name</font>": "Dark Vador",
        "<font color="orange">pos</font>": [1100, 300],
        "<font color="orange">weapon_id</font>": 0,
        "<font color="orange">texture_path</font>": "templates/menu/ship2.png",
        "<font color="orange">hp</font>" : 100,
        "<font color="orange">shield</font>": 100,
        "<font color="orange">quest_id</font>": 0,
        "<font color="orange">repair_value</font>": 10,
        "<font color="orange">action_number</font>": 3,
        "<font color="orange">damage</font>": 10
    },
}</pre>
<table>
    <thead>
        <tr>
            <th>Value's name</th>
            <th>Usage</th>
            <th>type</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>name</td>
            <td>Contains the ennemy's name.</td>
            <td><font color="red">char *</td></font>
        </tr>
        <tr>
            <td>pos</td>
            <td>Always leave 1100, 300.</td>
            <td><font color="red">sfVector2f</td></font>
        </tr>
        <tr>
            <td>weapon_id</td>
            <td>Contains the ennemy's equiped weapon.</td>
            <td><font color="red">item_id</td></font>
        </tr>
        <tr>
            <td>texture_path</td>
            <td>Filepath to the sprite sheet of your ennemy.</td>
            <td><font color="red">char *</td></font>
        </tr>
        <tr>
            <td>hp</td>
            <td>Contains the ennemy's hp.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>shield</td>
            <td>Contains the ennemy's shield.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>repair_value</td>
            <td>Value to know how much he's going to heal everytime he does a repair action.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>action_number</td>
            <td>Contains the number of actions the ennemy can make every turn.</td>
            <td><font color="red">int</td></font>
        </tr>
        <tr>
            <td>damage</td>
            <td>Contains the ennemy's damage of each attack.</td>
            <td><font color="red">int</td></font>
        </tr>
    </tbody>
</table>
<br><a href="../dev_doc.md"><h2>Go back to the heading documentation page</h2></a>
