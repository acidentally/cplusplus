'use strict';

async function test() {
    let response = await fetch('https://www.facebook.com/profile.php?id=61568341961135');
    console.log(response);
}
test()