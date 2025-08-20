📦Packaging Material Recommendation and Evaluation System
A simple C program to explore different packaging materials, their costs, recyclability, and seasonal suitability. Perfect for students, developers, or anyone curious about sustainable packaging! 🌱

🚀 Features
Displays detailed information about 14 different packaging materials.

Shows cost, recyclability, pros, cons, and suitability for rain, summer, and winter. 🌦️☀️❄️

Handles subcategories of materials like Paper, Aluminum, and Cardboard.

Case-insensitive input for easy use.

🛠️ How to Run
Clone or download this repository.

Compile the C program:

bash
Copy
Edit
gcc packaging_info.c -o packaging_info
Run the program:

bash
Copy
Edit
./packaging_info
Enter a packaging material (e.g., Plastic, Paper, Aluminum) and follow prompts for subcategories if needed.

📋 Materials Covered
Plastic

Glass

Polythene

Aluminum (Aluminum Foil, Aluminum Cans)

Biodegradable Plastic

Paper (Kraft Paper Unbleached, Kraft Paper Bleached, Recycled Kraft Paper, Paperboard)

Cardboard (Corrugated Cardboard, Folding Cartons)

🌟 Example Output
yaml
Copy
Edit
Enter a packaging material (Plastic, Glass, Paper, Polythene, Aluminum, Biodegradable Plastic, Cardboard): Plastic

--- Material Info ---
Material         : Plastic
Cost             : Low
Recyclability    : No
Good for Rain    : Yes
Good for Summer  : Yes
Good for Winter  : Yes
Advantages       : Cheap, lightweight, versatile, waterproof
Disadvantages    : Pollutes, hard to recycle, non-biodegradable
💡 Notes
The program uses fgets to handle input safely.

All input is converted to lowercase to make searches case-insensitive.

Subcategories prompt ensures detailed selection for materials like Paper, Aluminum, and Cardboard.

📝 License
This project is licensed under the MIT License – see the LICENSE file for details.

🤝 Contributing
Feel free to improve the program by adding more materials, better formatting, or extra features!

🛠 **Made with ❤️ by Kartik Bhardwaj**
