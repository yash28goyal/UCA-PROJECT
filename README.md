<h1>Student Database Management System</h1>

<img src="./images/image.wepb">

<h2>Overview</h2>
<p>The <strong>Student Database Management System</strong> is a console-based application written in C. This system allows teachers to manage student data efficiently and provides students with an interface to view their personal information and upcoming examinations or tests.</p>

<h2>Features</h2>

<h3>For Students:</h3>
<ul>
    <li><strong>View Details:</strong> After logging in, students can view their details, including:
        <ul>
            <li>Marks</li>
            <li>Attendance</li>
            <li>Father's Name</li>
            <li>Mother's Name</li>
            <li>Class</li>
            <li>Phone Number</li>
            <li>Roll Number</li>
            <li>Age</li>
            <li>Date of Birth (DOB)</li>
            <li>Mentor Name</li>
        </ul>
    </li>
    <li><strong>Upcoming Examinations:</strong> Students can choose to view the list of upcoming examinations or tests.</li>
</ul>

<h3>For Teachers:</h3>
<ul>
    <li><strong>Add Student:</strong> Teachers can add a new student to the database.</li>
    <li><strong>Remove Student:</strong> Teachers can remove a student from the database using the roll number.</li>
    <li><strong>View Student Details:</strong> Teachers can retrieve details of a specific student by entering their roll number.</li>
    <li><strong>Update Student Details:</strong> Teachers can update any student details as necessary.</li>
    <li><strong>Manage Examinations:</strong> Teachers can add upcoming examinations or tests to the system.</li>
    <li><strong>Filter by Mentor Name:</strong> Teachers can view a list of students in their class filtered by mentor name. Only students with the same mentor name are shown in the list.</li>
</ul>

<h2>Getting Started</h2>

<h3>Prerequisites</h3>
<p>To run this project, you'll need:</p>
<ul>
    <li>A C compiler (e.g., GCC)</li>
    <li>Basic knowledge of C programming</li>
</ul>

<h2>Installation</h2>
    <p>To set up the project locally, follow these steps:</p>
    <pre><code>git clone https://github.com/yash28goyal/UCA-PROJECT.git
    cd UCA-PROJECT
    # Additional setup steps (e.g., installing dependencies) go here
    </code></pre>

    <h2>Usage</h2>
    <p>After setting up the project, run the application with the following command:</p>
    <pre><code>gcc main.c -o UCA-Project
    ./UCA-Project
    </code></pre>
    <p>Follow the on-screen instructions to log in as a student or teacher and manage student data.</p>


<h2>Project Structure</h2>
<pre><code>student-database-management-system/
│
├── StudentManagementSystem.c       # Main file containing the program logic
├── user.csv                        # source file containind database of user register
├── student.csv                     # Source file containing database of student
├── exam.csv                        # Source file for exam and test details
└── README.md                       # Project documentation
</code></pre>

<h2>Usage</h2>
<p>- Upon running the program, the user will be prompted to log in as either a student or a teacher.<br>
- Based on the role, the user can access different features as listed above.<br>
- Follow the on-screen instructions to navigate through the system.</p>

<h2>Contributing</h2>
    <p>Contributions are welcome! Please follow these steps to contribute:</p>
    <ul>
        <li>Fork the repository.</li>
        <li>Create a new branch (<code>git checkout -b feature-branch</code>).</li>
        <li>Make your changes and commit them (<code>git commit -m 'Add some feature'</code>).</li>
        <li>Push to the branch (<code>git push origin feature-branch</code>).</li>
        <li>Create a new Pull Request.</li>
    </ul>
<h2>Contact</h2>
<p>For any questions or feedback, please contact:</p>
<ul>
    <li><strong>Your Name:</strong> <a href="mailto:yashgoyal414@gmail.com">yashgoyal414@gmail.com</a></li>
    <li><a href="https://github.com/yash28goyal">GitHub Profile</a></li>
</ul>
