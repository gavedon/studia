var blocks = document.getElementsByClassName("block");
var act_block = 0;
var size = blocks.length;
var max_y = 100;
var step = 1;
var dir = 1;
var act_block_pos = 0;

function slide() {
    if (act_block_pos >= max_y && dir == 1) {
        act_block += 1;
        act_block_pos = 0;
        if (act_block == size) {
            dir *= -1;
        }
    } else if (act_block_pos <= 0 && dir == -1) {
        act_block -= 1;
        act_block_pos = max_y;
        if (act_block == -1) {
            dir *= -1;
        }
    }
    act_block_pos += step * dir;
    let bblock = blocks[act_block];
    bblock.style.top = act_block_pos + "px";
}

setInterval(function() {
        slide()
    }

    , 1);