# 🎓 Student Management System – Montpellier Ynov Campus

Ce projet est un **système de gestion des étudiants** développé en POO avec une API. Il permet la gestion des étudiants, professeurs, cours, et inscriptions via une API sécurisée par une clé.

---

## 🚀 Lancement de l'API

### 1. Aller dans le dossier `build/`

```bash
cd build
````

### 2. Exécuter le binaire

```bash
./StudentManagementSystem
```

### 3. Exporter la clé API

Pour sécuriser les appels API, la clé est stockée dans une variable d’environnement.

```bash
export API_SECRET_KEY="5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650"
```

Vous pouvez vérifier que la clé est bien exportée :

```bash
echo $API_SECRET_KEY
```

---

## 🔐 Authentification

Certaines requêtes POST nécessitent un en-tête `ApiKey` avec la valeur de la clé API.

---

## 📡 Endpoints disponibles

### ✅ Endpoints GET

| Description             | Méthode | URL                                         |
| ----------------------- | ------- | ------------------------------------------- |
| Test de l’API           | GET     | `http://localhost:8080/api`                 |
| Liste des étudiants     | GET     | `http://localhost:8080/api/students`        |
| Détails d’un étudiant   | GET     | `http://localhost:8080/api/students/{id}`   |
| Liste des professeurs   | GET     | `http://localhost:8080/api/professors`      |
| Détails d’un professeur | GET     | `http://localhost:8080/api/professors/{id}` |
| Liste des cours         | GET     | `http://localhost:8080/api/courses`         |
| Détails d’un cours      | GET     | `http://localhost:8080/api/courses/{id}`    |

---

### ✍️ Endpoints POST

Toutes les requêtes POST ci-dessous nécessitent l'en-tête suivant :

```bash
-H "ApiKey: 5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650"
```

#### ➕ Ajouter un professeur

```bash
curl -X POST -H "ApiKey: ..." \
-d '{"Name": "Dr. Smith", "age": 45}' \
http://localhost:8080/api/professors
```

#### ➕ Ajouter un étudiant

```bash
curl -X POST -H "ApiKey: ..." \
-d '{"Name": "John Doe", "age": 20, "grades": [85.5, 90.0, 88.0]}' \
http://localhost:8080/api/students
```

#### ➕ Ajouter un cours

```bash
curl -X POST -H "ApiKey: ..." \
-d '{"courseCode": "CS101", "courseName": "Introduction to Computer Science", "creditHours": 3}' \
http://localhost:8080/api/courses
```

#### 📝 Inscrire une personne à un cours

##### Étudiant :

```bash
curl -X POST -H "ApiKey: ..." \
-d '{"who": "Student", "courseCode": "CS101", "name": "John Doe", "age": 20}' \
http://localhost:8080/api/enroll
```

##### Professeur :

```bash
curl -X POST -H "ApiKey: ..." \
-d '{"who": "Professor", "courseCode": "CS101", "name": "Dr. Smith", "age": 45}' \
http://localhost:8080/api/enroll
```
