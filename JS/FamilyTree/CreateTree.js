
const fs = require('fs');

let rawdata = fs.readFileSync('ex.json');
const dogList = JSON.parse(rawdata);

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

function getParents(dog, list, gen, dKey)
{
    var parents = new Object();
    var rents = getParentNames(dog);
    for(x in rents)
    {
        if (rents[x] != "")
        {
            for (let i = 0; i < list.length; i++)
            {
                if (rents[x] == list[i].name)
                {
                    var key = createParentKey(dog, list[i].g, gen, dKey);
                    parents[key] = list[i];
                }
            }
        }
    }
    return parents; 
}

function createParentKey(child, pgender, generation, k)
{
    if (generation == 0){
        var childID = dogID(child, generation);
    }
    else{ childID = k;}
    var id = "P"+ pgender+ generation +"_"+ childID;
    return id;
}

function dogID(dog, gen, key)
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
        dogID = "P" + dog.g + gen + "_"+ key;
    }
    return dogID;
}

function getParentNames(dog)
{
    var result = Object();
    var dad = dog["pm"];
    var mom = dog["pf"];
    result["pf"] = mom;
    result["pm"] = dad;
    return result;
}

function getGeneration(rels, gen)
{
    var parents;
    var result = new Object();
    if (gen == 0){
        var sibs = new Object();
        parents = getParents(rels, dogList, gen, "");

        if (!isEmpty(parents)){

            var id = dogID(rels, gen, "empty");
            result[id] = parents;
            
        }
        else{ return "end";}
    }

    else{
        if (!isEmpty(rels) && rels != null && rels != undefined){
            for (x in rels){
                var id = x;
                parents = getParents(rels[x], dogList, gen, id);
                if (!isEmpty(parents) && parents != null && parents != undefined){
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

function isEmpty(relArr){return (!Object.keys(relArr).length);}

function genKey(gen) {return "gen_"+ gen;}

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
            if ( temp != "end" && temp != undefined && temp != null && !isEmpty(temp))
            {
                result[key] = temp;
                nextGen = getNewRels(result[key]);
                gen++;
            }
            else{ nextGen = "end";}
        }
    }
    return result;
}
// ----------------------tests -------------------------
console.log(createTree(dogList[0]));