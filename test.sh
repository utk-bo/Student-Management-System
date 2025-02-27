#!/bin/bash

API_KEY="5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650"

echo "GET /api"
curl -X GET http://localhost:8080/api
sleep 2

echo "GET /api/students"
curl -X GET http://localhost:8080/api/students
sleep 2

echo "GET /api/professors"
curl -X GET http://localhost:8080/api/professors
sleep 2

echo "GET /api/courses"
curl -X GET http://localhost:8080/api/courses
sleep 2

echo "GET /api/students/1"
curl -X GET http://localhost:8080/api/students/1
sleep 2

echo "GET /api/professors/1"
curl -X GET http://localhost:8080/api/professors/1
sleep 2

echo "GET /api/courses/1"
curl -X GET http://localhost:8080/api/courses/1
sleep 2

echo "POST /api/professors"
curl -X POST -H "ApiKey: $API_KEY" -d '{"Name": "Dr. Smith", "age": 45}' http://localhost:8080/api/professors
sleep 2

echo "POST /api/students"
curl -X POST -H "ApiKey: $API_KEY" -d '{"Name": "John Doe", "age": 20, "grades": [85.5, 90.0, 88.0]}' http://localhost:8080/api/students
sleep 2

echo "POST /api/courses"
curl -X POST -H "ApiKey: $API_KEY" -d '{"courseCode": "IT101", "courseName": "Introduction to Computer Science", "creditHours": 3}' http://localhost:8080/api/courses
sleep 2

echo "POST /api/enroll (Student)"
curl -X POST -H "ApiKey: $API_KEY" -d '{"who": "Student", "courseCode": "IT101", "name": "John Doe", "age": 20}' http://localhost:8080/api/enroll
sleep 2

echo "POST /api/enroll (Professor)"
curl -X POST -H "ApiKey: $API_KEY" -d '{"who": "Professor", "courseCode": "CS101", "name": "Dr. Smith", "age": 45}' http://localhost:8080/api/enroll
sleep 2

echo "POST /api/professors (new professor)"
curl -X POST -H "ApiKey: $API_KEY" -d '{"Name": "Dr. Johnson", "age": 50}' http://localhost:8080/api/professors
sleep 2

echo "POST /api/students (new student)"
curl -X POST -H "ApiKey: $API_KEY" -d '{"Name": "Alice Wonder", "age": 22, "grades": [2.5, 8.0, 9.0]}' http://localhost:8080/api/students
sleep 2

echo "POST /api/courses (new course)"
curl -X POST -H "ApiKey: $API_KEY" -d '{"courseCode": "DATA101", "courseName": "Data Structures", "creditHours": 4}' http://localhost:8080/api/courses
sleep 2

echo "GET /api/students"
curl -X GET http://localhost:8080/api/students
sleep 2

echo "GET /api/professors"
curl -X GET http://localhost:8080/api/professors
sleep 2

echo "GET /api/courses"
curl -X GET http://localhost:8080/api/courses
sleep 2

echo "GET /api/students/1"
curl -X GET http://localhost:8080/api/students/1
sleep 2

echo "GET /api/professors/1"
curl -X GET http://localhost:8080/api/professors/1
sleep 2

echo "GET /api/courses/1"
curl -X GET http://localhost:8080/api/courses/1
sleep 2
