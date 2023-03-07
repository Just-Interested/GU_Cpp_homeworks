function getShapePoints(shape, x, y, scale = 1){
    var shapes = {"star": 0, "ring": 1, "house": 2, "hourglass": 3};
    var shape_number = shapes[shape];
    console.log(shape_number)
    var coords = [];
    switch (shape_number){
    case 0:
        var arms = 5
        let angle = Math.PI / arms;
        var innerRadius = 50 * scale / 2
        var outerRadius = 50 * scale
        for (let i = 0; i < 2 * arms; i++) {
            let r = (i % 2) ? innerRadius : outerRadius;
            let currX = x + Math.cos(i * angle) * r;
            let currY = y + Math.sin(i * angle) * r;
            coords.push(Array(currX, currY));
        }
        return coords;
    case 1:
        var radius = 50 * scale
        for (let i = 0; i < 360; i += 10) {
            let currX = x + Math.cos(i * Math.PI / 180) * radius;
            let currY = y + Math.sin(i * Math.PI / 180) * radius;
            coords.push(Array(currX, currY));
        }
        return coords;
    case 2:
        var width = 50 * scale;
        var height = 80 * scale;
        coords.push(Array(x + width / 2, y));
        coords.push(Array(x + width / 2, y + height / 2));
        coords.push(Array(x - width / 2, y + height / 2));
        coords.push(Array(x - width / 2, y));
        coords.push(Array(x, y - height / 2));
        coords.push(Array(x + width / 2, y));
//        coords.push(Array(x - width / 2, y));
        return coords;

    case 3:
        var width = 40 * scale;
        var height = 80 * scale;
        coords.push((Array(x - width/2, y - height/2)));
        coords.push((Array(x + width/2, y - height/2)));
        coords.push((Array(x - width/2, y + height/2)));
        coords.push((Array(x + width/2, y + height/2)));
        coords.push((Array(x - width/2, y - height/2)));
        return coords;
    }
}
