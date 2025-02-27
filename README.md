#Projet POO API: Student-Management-System 
###Student Management System by Montpellier Ynov campus 

pour lancer l'api aller dans /build et executer ./StudentManagementSystem

#API_SECRET_KEY ====>  5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650 

export API_SECRET_KEY="5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650"  entrez cette commande dans un terminal bash 

echo $API_SECRET_KEY renverra 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650

cela permet que la clef api ne soit pas dans le code source mais sur le serveur qui heberge l'api

ensuit vous pourrez faire toute les requête suivantes:

curl -X GET http://localhost:8080/api

curl -X GET http://localhost:8080/api/students

curl -X GET http://localhost18080/api/professors

curl -X GET http://localhost:8080/api/courses

curl -X GET http://localhost:8080/api/students/{id}

curl -X GET http://localhost:8080/api/professors/{id}

curl -X GET http://localhost:8080/api/courses/{id}

curl -X POST -H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650" -d '{"Name": "Dr. Smith", "age": 45}' http://localhost:8080/api/professors

curl -X POST -H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650" -d '{"Name": "John Doe", "age": 20, "grades": [85.5, 90.0, 88.0]}' http://localhost:8080/api/students

curl -X POST -H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650" -d '{"courseCode": "CS101", "courseName": "Introduction to Computer Science", "creditHours": 3}' http://localhost:8080/api/courses

curl -X POST -H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650" -d '{"who": "Student", "courseCode": "CS101", "name": "John Doe", "age": 20}' http://localhost:8080/api/enroll

curl -X POST -H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650" -d '{"who": "Professor", "courseCode": "CS101", "name": "Dr. Smith", "age": 45}' http://localhost:8080/api/enroll


