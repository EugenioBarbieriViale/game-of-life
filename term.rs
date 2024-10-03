// use rand::Rng;

const WIDTH: usize = 10;
const HEIGHT: usize = WIDTH * 2;

fn main() {
    let mut states = [[false; HEIGHT as usize]; WIDTH as usize];

    states[5][5] = true;

    draw_grid(&states);
}

fn draw_grid(states: &[[bool; HEIGHT as usize]; WIDTH as usize]) {
    for row in 0..WIDTH {
        for col in 0..HEIGHT {
            if states[row][col] {
                print!("@");
            }
            else {
                print!(".");
            }
        }
        println!("");
    }
}
