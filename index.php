<?php 


// Mise en place du système de routage

            // Définition constance une route absolue vers les ressources du site
            define("URL", str_replace("index.php", "", (isset($_SERVER['HTTPS']) ? "https" : "http") . 
            "://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]"));
            //  http://localhost/ressourcedemandée.
            
            
            try{
            
                if(empty($_GET['page'])){
            
                    throw new Exception("La page n'existe pas");
            
                }else{
                    $url = explode("/", filter_var($_GET['page'], FILTER_SANITIZE_URL));
            
                    switch($url[0]){
                        case 'admin': 
                            if(empty($url[1])) throw new Exception("La page n'existe pas");
                            switch ($url[1]){
                                case 'login' : echo "La page login"; 
                                    break;
                                case 'connexion' : echo "La page connexion";
                                    break;
                                case 'adminPanel' : echo "La page adminPanel";
                                    break;
                                case 'deconnexion' : echo "La page deconnexion";
                                    break;
                                default: throw new Exception("La page n'existe pas");

                            }
                            break;
                        case 'front' : 
                            if(empty($url[1])) throw new Exception("La page n'existe pas");
                            switch ($url[1]){
                                case 'home' : echo "La page home";
                                    break;
                                case 'contact' : echo "La page contact";
                                    break;
                                default: throw new Exception("La page n'existe pas");
                            }
                            break;
                    }
                }
            
            }catch(PDOException $e){
                echo $e->getMessage();
            }