
const char webpage[] = R"=====(
<!DOCTYPE html>
<html>
    <head>
      <meta charset="UTF-8">
      <title>LAP TRINH</title>
    </head>
    <body>
       <div>
           NHIET DO  :  <span id="nhietdos">0</span>*C<br>
           DO AM     :  <span id="doams">0</span>%<br>
       </div>
       <script>
        setInterval(function(){
            getnhietdo();
            getdoam();

        },1000);
        function getnhietdo(){
            var xhttp= new XMLHttpRequest();
            xhttp.onreadystatechange=function(){
                if(this.readyState==4 && this.status==200){
                    document.getElementById("nhietdos").innerHTML=this.responseText;
                }
            };
            xhttp.open("GET","docnhietdo",true);
            xhttp.send;
        }
        function getdoam(){
            var xhttp= new XMLHttpRequest();
            xhttp.onreadystatechange=function(){
                if(this.readyState==4 && this.status==200){
                    document.getElementById("doams").innerHTML=this.responseText;
                }
            };
            xhttp.open("GET","docdoam",true);
            xhttp.send;
        }

    </script>
    </body>
    
</html>

)=====";