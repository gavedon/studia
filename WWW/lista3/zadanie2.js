var brd = Array("Ford", "Fiat");
var mdl = Array(Array("Fiesta", "Focus"));
mdl.push(Array("500", "Bravo"));

var brdlist = document.getElementById('brand');
brdlist.onclick = function() {
    brandlist();
    clearmdlist();
}

var mdlist = document.getElementById('model');
mdlist.onclick = function() {
    modellist();
}

var addbtn = document.getElementById('btn');
addbtn.onclick = function() {
    addelem();
}

function brandlist() {
    for (var i = brdlist.length; i < brd.length; i++) {
        var e = document.createElement("option");
        var t = document.createTextNode(brd[i]);
        e.append(t);
        brdlist.append(e);
    }
}

function clearmdlist() {
    var L = mdlist.options.length - 1;
    for (var i = L; i >= 0; i--) {
        mdlist.remove(i);
    }
}


function modellist() {
    var idx = brd.indexOf(brdlist.value);
    for (var i = mdlist.length; i < mdl[idx].length; i++) {
        var e = document.createElement("option");
        var t = document.createTextNode(mdl[idx][i]);
        e.append(t);
        mdlist.add(e);
    }
}


function addelem() {
    var nnew = document.getElementById('new').value;
    if (document.getElementById('mdl').checked) {
        var x = brd.indexOf(brdlist.value);
        if (x != -1) {
            mdl[x].push(nnew);
        }

    } else {
        brd.push(nnew);
        mdl.push(Array());
    }
}