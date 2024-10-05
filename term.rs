// use rand::Rng;

const HEIGHT: usize = 10;
const WIDTH: usize = HEIGHT * 2;

fn main() {
    let mut states = [[false; WIDTH]; HEIGHT];

    states[4][4] = true;

    run(&states);
}

fn run(states: &[[bool; WIDTH]; HEIGHT]) {
    loop {
        for y in 0..HEIGHT {
            for x in 0..WIDTH {
                let n = count_neighbours(x, y, &states);

                draw(x, y, &states);
            }
            println!("");
        }
    }
}

fn count_neighbours(x: usize, y: usize, states: &[[bool; WIDTH]; HEIGHT]) -> usize {
    let mut n = 0;

    for j in 0..=2 {
        for i in 0..=2 {
            if x != 0 && y != 0 && x != WIDTH-1 && y != HEIGHT-1 {
                let new_y: usize = y + (i as usize).abs_diff(1usize);
                let new_x: usize = x + (j as usize).abs_diff(1usize);

                if states[new_y][new_x] && (j != 1 || i != 1) {
                    n += 1;
                }
            }
        }
    }
    n
}

fn draw(x: usize, y: usize, states: &[[bool; WIDTH]; HEIGHT]) {
    if states[y][x] {
        print!("@");
    }
    else {
        print!(".");
    }
}
