use rand::thread_rng;
use rand_distr::{Distribution, Normal};

fn main() {
    let real_temp:f64 = 23.0;
    // println!("The real temperature is {}!", real_temp);
    println!("Real, Estimate, Est_Uncert, Gain, Measurement, Meas_Uncert");

    // Initial values
    let mut x:f64 = 18.0;
    let mut p:f64 = 5.0;
    let r:f64 = 3.0;
    let normal = Normal::new(real_temp, r).unwrap();
    let mut rng = thread_rng();
    println!("{}, {}, {}, {}, {}, {}", real_temp, x, p, 0.0, 0.0, r);

    for _n in 1..80 {
        let k = get_kalman_gain(p, r);
        let z = normal.sample(&mut rng);
        x = get_updated_state(x, k, z);
        p = get_updated_uncertainty(k, p);
        // println!("x: {}, p: {}, k: {}, z: {}", x, p, k, z);
        println!("{}, {}, {}, {}, {}, {}", real_temp, x, p, k, z, r);
    }
}

fn get_kalman_gain(p:f64, r:f64) -> f64{
    p / (p+r)
}

fn get_updated_state(x_last:f64, k:f64, z:f64) -> f64{
    x_last + k * (z - x_last)
}

fn get_updated_uncertainty(k:f64, p_last: f64) -> f64{
    (1.0 - k) * p_last
}