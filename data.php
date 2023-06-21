<?php

if (isset($_GET['data'])) {

  // Obtener el dato enviado desde Arduino

  $data = $_GET['data'];

  // Mostrar el dato en la página web

  echo "Dato recibido: " . $data;

}

?>
