
const fs = require('fs');

let rawdata = fs.readFileSync('ex.json');
const dogList = JSON.parse(rawdata);

//---------------------- CREATE ZONE --------------------

//---------------------- HELPERS ------------------------
function getParentNames(dog)
{
    var result = Object();
    var dad = dog["pm"];
    var mom = dog["pf"];
    result["pf"] = mom;
    result["pm"] = dad;
    return result;
}

function genKey(gen) {return "gen_"+ gen;}

function isEmpty(relArr){return (!Object.keys(relArr).length);}

function createParentKey(child, pgender, generation)
{
    var childID = dogID(child, generation);
    var id = "P"+ pgender+ generation +"_"+ childID;
    return id;
}
//---------------------- CORE ----------------------------

function getParents(dog, list, gen)
{
    var parents = new Object();
    var rents = getParentNames(dog);
    for(x in rents)
    {
        if (rents[x] != "")
        {
            for (let i = 0; i < dogList.length; i++)
            {
                if (rents[x] == dogList[i].name)
                {
                    var key = createParentKey(dog, dogList[i].g, gen);
                    parents[key] = dogList[i];
                }
            }
        }
    }
    return parents; 
}



function getChildren(dog, dogList)
{
    var name = dog.name;
    var children = new Array()
    var y = 0;
    for (x in dogList)
    {
        if (dogList[x].pf == name || dogList[x].pm == name)
        {
            children.push(dogList[x]);
            y++;
        }
    }
    if (y != 0){return children;}
    else {return [];}
}

function getGeneration(rels, gen)
{
    var parents;
    var result = new Object();
    if (gen == 0){
        var sibs = new Object();
        parents = getParents(rels, dogList, gen)

        if (!isEmpty(parents)){

            var id = dogID(rels, gen);
            result[id] = parents;
            
        }
        else{ return "end";}
    }

    else{
        if (!isEmpty(rels) && rels != null && rels != undefined){
            for (x in rels){
                parents = getParents(rels[x], dogList, gen);
                if (!isEmpty(parents) && parents != null && parents != undefined){
                    var id = dogID(rels[x], gen);
                    result[id] = parents;
                }
            }
        }
        else{
            return "end";
        }
    }
    return result;
}

function createTree(genesis)
{
    var result = Object();
    var nextGen = Object();
    var rel;
    var gen = 0;
    while (nextGen != "end" && nextGen != undefined && nextGen != null)
    {
        if (gen == 0)
        {
            rel = genesis;
            nextGen = getGeneration(rel, gen);
            var key = genKey(gen);
            if (nextGen != "end"){
                result[key] = nextGen;
                nextGen = getNewRels(result[key]);
                gen++;
            }
        }
        else
        {
            var key = genKey(gen);
            var temp = getGeneration(nextGen, gen);
            if ( temp != "end" && temp != undefined && temp != null)
            {
                result[key] = getGeneration(nextGen, gen);
                nextGen = getNewRels(result[key]);
                gen++;
            }
            else{ nextGen = "end";}
        }
    }
    return result;
}

function getNewRels(generation)
{
    var newGen = Object();
    if(generation != "end" )
    {
        for (x in generation)
        {
            var branch = generation[x];
            for (y in branch)
            {
                newGen[y] = branch[y];
            }
            
        }
    }
    else { newGen = "end";}
    return newGen;
}

function dogID(dog, gen)
{
    var dogID;
    if (gen == 0)
    {
        var cID = new Array
        var temp = dog.name.split('');
        var i = 0;
        while(i < 3)
        {
           cID.push(temp[i]);
           i++;
        }
        dogID = cID.join("");
    }
    else
    {if (dog != null && dog != undefined)

        dogID = Object.keys(dog)[0];
    }
    return dogID;
}

//-------------------------TEST ZONE ----------------
console.log("\n");
console.log(getParents(dogList[0]), dogList, 0);