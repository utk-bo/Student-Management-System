#Projet POO API: Student-Management-System 
###Student Management System by Montpellier Ynov campus 

pour lancer l'api aller dans /build et executer ./StudentManagementSystem

#apikeys ====>  5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650

ensuit vous pourrez faire toute les requête suivantes:

curl -X GET http://localhost:8080/api

curl -X GET http://localhost:8080/api/students

curl -X GET http://localhost18080/api/professors

curl -X GET http://localhost:8080/api/courses

curl -X GET http://localhost:8080/api/students/{id}

curl -X GET http://localhost:8080/api/professors/{id}

curl -X GET http://localhost:8080/api/courses/{id}

curl -X POST -H "ApiKey: YOUR_SECRET_KEY" -d '{"Name": "Dr. Smith", "age": 45}' http://localhost:8080/api/professors

curl -X POST -H "ApiKey: YOUR_SECRET_KEY" -d '{"Name": "John Doe", "age": 20, "grades": [85.5, 90.0, 88.0]}' http://localhost:8080/api/students

curl -X POST -H "ApiKey: YOUR_SECRET_KEY" -d '{"courseCode": "CS101", "courseName": "Introduction to Computer Science", "creditHours": 3}' http://localhost:8080/api/courses

curl -X POST -H "ApiKey: YOUR_SECRET_KEY" -d '{"who": "Student", "courseCode": "CS101", "name": "John Doe", "age": 20}' http://localhost:8080/api/enroll

curl -X POST -H "ApiKey: YOUR_SECRET_KEY" -d '{"who": "Professor", "courseCode": "CS101", "name": "Dr. Smith", "age": 45}' http://localhost:8080/api/enroll


