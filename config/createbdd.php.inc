<?php 

try{
    $pdo = new PDO("mysql:host=localhost",'root', '');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    if($pdo->exec('CREATE DATABASE gestion_sport') !==false){
        $serveur_gestion = new PDO("mysql:host=localhost;dbname=gestion_sport",'root', '');

        if($serveur_gestion->exec('CREATE TABLE clients(
            id INT(11) AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR(50) NOT NULL,
            email VARCHAR(50) NOT NULL,
            phone VARCHAR(50) NOT NULL,
            activity VARCHAR(50) NOT NULL,
            logo VARCHAR(150) NOT NULL,
            url VARCHAR(150) NOT NULL,
            contact_com VARCHAR(50) NOT NULL,
            contact_tech VARCHAR(50) NOT NULL,
            description TEXT(150) NOT NULL
        )') !==false){
            if($serveur_gestion->exec('CREATE TABLE contrats(
                id INT(11) AUTO_INCREMENT PRIMARY KEY,
                name VARCHAR(50) NOT NULL
            )') !==false){
                if($serveur_gestion->exec('CREATE TABLE partners(
                    id INT(11) AUTO_INCREMENT PRIMARY KEY,
                    name VARCHAR(50) NOT NULL,
                    email VARCHAR(50) NOT NULL,
                    phone VARCHAR(50) NOT NULL,
                    description TEXT(150) NOT NULL,
                    url VARCHAR(150) NOT NULL,
                    is_active BOOLEAN NOT NULL,
                    contratId INT(11) NOT NULL,
                    FOREIGN KEY(contratId) REFERENCES contrats(id)
                )') !==false){
                    if($serveur_gestion->exec('CREATE TABLE partners_clients(
                        partnerId INT(11) NOT NULL,
                        clientId INT(11) NOT NULL,
                        FOREIGN KEY(partnerId) REFERENCES partners(id),
                        FOREIGN KEY(clientId) REFERENCES clients(id)
                    )') !==false){
                        if($serveur_gestion->exec('CREATE TABLE salles(
                            id INT(11) AUTO_INCREMENT PRIMARY KEY,
                            name VARCHAR(50) NOT NULL,
                            email VARCHAR(50) NOT NULL,
                            adress VARCHAR(50) NOT NULL,
                            phone VARCHAR(50) NOT NULL,
                            is_active BOOLEAN NOT NULL,
                            partnerId INT(11) NOT NULL,
                            FOREIGN KEY(partnerId) REFERENCES partners(id)
                        )') !==false){
                            if($serveur_gestion->exec('CREATE TABLE permissions(
                                id INT(11) AUTO_INCREMENT PRIMARY KEY,
                                name BOOLEAN NOT NULL
                            )') !==false){
                                if($serveur_gestion->exec('CREATE TABLE salles_perms(
                                    salleId INT(11) NOT NULL,
                                    permissionId INT(11) NOT NULL,
                                    FOREIGN KEY(salleId) REFERENCES salles(id),
                                    FOREIGN KEY(permissionId) REFERENCES permissions(id)
                                )') !==false){
                                    if($serveur_gestion->exec('CREATE TABLE branches(
                                        id INT(11) AUTO_INCREMENT PRIMARY KEY,
                                        name VARCHAR(50) NOT NULL
                                    )') !==false){
                                        if($serveur_gestion->exec('CREATE TABLE salles_branches(
                                            salleId INT(11) NOT NULL,
                                            branchId INT(11) NOT NULL,
                                            FOREIGN KEY(salleId) REFERENCES salles(id),
                                            FOREIGN KEY(branchId) REFERENCES branches(id)
                                        )') !==false){
    if($serveur_gestion->exec('CREATE TABLE zones(
                                                id INT(11) AUTO_INCREMENT PRIMARY KEY,
                                                name VARCHAR(50) NOT NULL
                                            )') !== false) {
        if($serveur_gestion->exec('CREATE TABLE salles_zones(
                                                    salleId INT(11) NOT NULL,
                                                    zoneId INT(11) NOT NULL,
                                                    FOREIGN KEY(salleId) REFERENCES salles(id),
                                                    FOREIGN KEY(zoneId) REFERENCES zones(id)
                                                )') !== false) {
            if($serveur_gestion->exec('CREATE TABLE users(
                                                        id INT(11) AUTO_INCREMENT PRIMARY KEY,
                                                        login VARCHAR(150) NOT NULL,
                                                        password VARCHAR(150) NOT NULL
                                                    )') !== false) {
                if($serveur_gestion->exec('INSERT INTO users(login, password)
                                                        VALUES("admin", "admin")') !== false) {
                    if($serveur_gestion->exec('INSERT INTO clients(name, email, phone, activity, logo, url, contact_com, contact_tech, description)
                                                            VALUES
                                                            ("Client 1", "client1@gmail.com", "0606060606", "Activité 1", "logo1.png", "url1.com", "client_com1", "client_tech1", "description11"),
                                                            ("Client 2", "client2@gmail.com", "0606060606", "Activité 2", "logo2.png", "url2.com", "client_com2", "client_tech2", "description22");
                                                            ') !== false) {
                        if($serveur_gestion->exec('INSERT INTO contrats(name)VALUES("Contrat 1"),("Contrat 2"), ("Contrat 3")') !== false) {
                            if($serveur_gestion->exec('INSERT INTO partners(name, email, phone, description, url, is_active, contratId)
                                                                    VALUES
                                                                    ("Partner 1", "partner1@gmail.com", "0606060606", "description1", "url1.com", 1, 1),
                                                                    ("Partner 2", "partner2@gmail.com", "0606060606", "description2", "url2.com", 1, 2),
                                                                    ("Partner 3", "partners3@gmail.com", "0606060606", "description3", "url3.com", 1, 3);
                                                                ') !== false) {
                                if($serveur_gestion->exec('INSERT INTO partners_clients(partnerId, clientId)
                                                                        VALUES
                                                                        (1, 1),
                                                                        (2, 2),
                                                                        (3, 1);
                                                                    ') !== false) {
                                    if($serveur_gestion->exec('INSERT INTO salles(name, email, adress, phone, is_active, partnerId)
                                                                            VALUES
                                                                            ("Salle 1", "salle1@gmail.com", "adress1", "0606060606", 1, 1),
                                                                            ("Salle 2", "salle2@gmail.com", "adress2", "0606060606", 1, 2),
                                                                            ("Salle 3", "salle3@gmail.com", "adress3", "0606060606", 1, 3);
                                                                    ') !== false) {
                                        if($serveur_gestion->exec('INSERT INTO permissions(name) VALUES("permission1"),("permission2"),("permission3")') !== false) {
                                            if($serveur_gestion->exec('INSERT INTO salles_perms(salleId, permissionId)
                                                                            VALUES
                                                                            (1, 1),
                                                                            (2, 2),
                                                                            (3, 3);
                                                                    ') !== false) {
                                                if($serveur_gestion->exec('INSERT INTO branches(name) VALUES("branch1"),("branch2"),("branch3")') !== false) {
                                                    if($serveur_gestion->exec('INSERT INTO salles_branches(salleId, branchId)
                                                                            VALUES
                                                                            (1, 1),
                                                                            (2, 2),
                                                                            (3, 3);
                                                                    ') !== false) {
                                                        if($serveur_gestion->exec('INSERT INTO zones(name) VALUES("zone1"),("zone2"),("zone3")') !== false) {
                                                            if($serveur_gestion->exec('INSERT INTO salles_zones(salleId, zoneId)
                                                                            VALUES
                                                                            (1, 1),
                                                                            (2, 2),
                                                                            (3, 3);
                                                                    ') !== false) {
                                                                echo 'Base de données créée avec succès';
                                                            } else {
                                                                echo 'Erreur lors de la création de la table users';
                                                            };
                                                        } else {
                                                            echo 'Erreur lors de la création de la table salle_zone';
                                                        };
                                                    } else {
                                                        echo 'Erreur lors de la création de la table zone';
                                                    };
                                                } else {
                                                    echo 'Erreur lors de la création de la table salle_branch';
                                                };
                                            } else {
                                                echo 'Erreur lors de la création de la table branch';
                                            };
                                        } else {
                                            echo 'Erreur lors de la création de la table salle_perms';
                                        };
                                    } else {
                                        echo 'Erreur lors de la création de la table permission';
                                    };
                                } else {
                                    echo 'Erreur lors de la création de la table salle';
                                };
                            } else {
                                echo 'Erreur lors de la création de la table partner_client';
                            };
                        } else {
                            echo 'Erreur lors de la création de la table partner';
                        };
                    } else {
                        echo 'Erreur lors de la création de la table contrat';
                    };
                } else {
                    echo 'Erreur lors de la création de la table client';
                };
            }
        }
    }
}
}
}
}
}
}
}
}
}
}

}catch(PDOException $error){
    echo $error->getMessage();
}