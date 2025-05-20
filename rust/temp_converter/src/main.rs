/*
 * Project Name: Temperature Converter
 * Author: Matthew Gasiorek
 * Created On: 2025-05-18
 * Last Modified: 2025-05-18
 * Description: Learning some of the basics of Rust by building a temperature converter.
 * Version: 1.0
 * Contact: matthew.gasiorek.coding@gmail.com
 */

/*
Starting off we are importing modules, namely std::io, which is Rust's standard library module for input/output
then we are importing ::{self, Write}
self: Imports the module itself, which allows you to use functions like io::stdin() and io::stdout().
(MAY NEED MORE EXPLANATION ON THIS LINE FOR WHY WE NEED TO USE THIS) Write: This is a trait (a collection of methods) that provides the flush() method, which we use later to force the buffer to output immediately.
*/
use std::io::{self, Write};

//similar to C code, we define our main function
fn main() {
    print!("Enter the temperature value: ");
}
