function limpar(){
  for(let elemento of document.getElementsByClassName("limpar")){
    elemento.value = '';
  }
  for(let elemento of document.getElementsByClassName("mensagens")){
    elemento.style.color = 'red';
  }
}
function criticaNome(idelemento,idmsg){
  let elemento = document.getElementById(idelemento).value;
  let letras = /[ a-zçñáâàäéêèëíîìïóôòöúûùü]/i;
  let exclusao = /[^ a-zçñáâàäéêèëíîìïóôòöúûùü]/i;
  let passou = false;
  if(elemento.split(" ").filter(e => e!=="").length > 1){
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'green';
    if(letras.test(elemento) && !exclusao.test(elemento)){
      document.querySelector("#" + idmsg + " li.letra").style.color = 'green';
      passou = true;
    }else{
      document.querySelector("#" + idmsg + " li.letra").style.color = 'red';
      passou = false;
    }
  }else{
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'red';
    if(letras.test(elemento) && !exclusao.test(elemento)){
      document.querySelector("#" + idmsg + " li.letra").style.color = 'green';
    }else{
      document.querySelector("#" + idmsg + " li.letra").style.color = 'red';
    }
    passou = false;
  }
  return passou;
}
function criticaCPF(idelemento,idmsg){
  let elemento = document.getElementById(idelemento).value;
  let padrao = /(\d{3}\.){2}\d{3}-\d{2}/;
  let numero = /[0-9]/;
  let exclusao = /[^0-9]/;
  if(numero.test(elemento.split('/[.-]/').join("")) && !exclusao.test(elemento)){
    document.querySelector("#" + idmsg + " li.numero").style.color = 'green';
  }else{
    document.querySelector("#" + idmsg + " li.numero").style.color = 'red';
  }
  if(padrao.test(elemento)){
    let cpf1 = '';
    let cpf2 = '';
    let digito = '';
    cpf1 = elemento.split('-')[0].split('.').filter(e => e !== '').join('');
    let soma = 0;
    for(let algarismo=0;algarismo<9;algarismo++){
      soma += (10-algarismo)*Number.parseInt(cpf1[algarismo]);
    }
    soma = soma % 11;
    if(soma>1){
      digito = (11-soma).toString();
    }else{
      digito = '0';
    }
    cpf1 += digito;
    soma = 0;
    for(let algarismo=0;algarismo<9;algarismo++){
      soma += (10-algarismo)*Number.parseInt(cpf1[algarismo+1]);
    }
    soma = soma % 11;
    if(soma>1){
      digito += (11-soma).toString();
    }else{
      digito += '0';
    }
    if(digito===elemento.split('-')[1]){
      document.querySelector("#" + idmsg + " li.valido").style.color = 'green';
      return true;
    }else{
      document.querySelector("#" + idmsg + " li.valido").style.color = 'red';
    }
  }else{
    document.querySelector("#" + idmsg + " li.valido").style.color = 'red';
  }
  return false;
}
function criticarSenha(idelemento,idmsg){
  let elemento = document.getElementById(idelemento).value;
  let letras = /[a-z]/i;
  let numeros = /[0-9]/;
  let simbolos = /[#$@&]/;
  let exclusao = /[^0-9a-z#$@&]/i;
  let passou = false;
  if(elemento.length>7 && elemento.length<13){
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'green';
    passou &= true;
  }else{
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'red';
    passou = false;
  }
  if(letras.test(elemento)){
    document.querySelector("#" + idmsg + " li.letra").style.color = 'green';
    passou &= true;
  }else{
    document.querySelector("#" + idmsg + " li.letra").style.color = 'red';
    passou = false;
  }
  if(numeros.test(elemento)){
    document.querySelector("#" + idmsg + " li.numero").style.color = 'green';
    passou &= true;
  }else{
    document.querySelector("#" + idmsg + " li.numero").style.color = 'red';
    passou = false;
  }
  if(simbolos.test(elemento)){
    document.querySelector("#" + idmsg + " li.simbolo").style.color = 'green';
    passou &= true;
  }else{
    document.querySelector("#" + idmsg + " li.simbolo").style.color = 'red';
    passou = false;
  }
  if(exclusao.test(elemento)){
    document.querySelector("#" + idmsg + " li.exclusivo").style.color = 'red';
    passou = false;
  }else{
    document.querySelector("#" + idmsg + " li.exclusivo").style.color = 'green';
    passou &= true;
  }
  return passou;
}
function criticaFormulario(){
  if(criticaNome('nome','msgnome') && criticaCPF('cpf','msgcpf') && criticarSenha('senha','msgsenha') && criticarSenha('confirmaSenha','msgconfirmaSenha')){
    if(document.getElementById('senha').value !== document.getElementById('confirmaSenha').value){
      document.getElementById("msgerro").innerText = 'As senhas devem ser iguais';
      document.getElementById("msgerro").style.color = 'red';
      document.getElementById('botaoLogin').disabled = true;
    }else{
      document.getElementById("msgerro").innerText = 'Tudo numa boa';
      document.getElementById("msgerro").style.color = 'green';
      document.getElementById('botaoLogin').disabled = false;
    }
  }else{
    document.getElementById("msgerro").innerText = 'Preencha os campos';
    document.getElementById("msgerro").style.color = 'red';
    document.getElementById('botaoLogin').disabled = true;
  }
}
function criticaChange(idelemento, idmsg) {
  let elemento = document.getElementById(idelemento).value;
  let letras = /[a-z]/i;
  let numeros = /[0-9]/;
  let simbolos = /[#$@&]/;
  let passou = true;
  if (elemento.length > 7 && elemento.length < 13) {
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'green';
    passou &= true;
  } else {
    document.querySelector("#" + idmsg + " li.tamanho").style.color = 'red';
    passou = false;
  }
  if (letras.test(elemento)) {
    document.querySelector("#" + idmsg + " li.letra").style.color = 'green';
    passou = passou & true;
  } else {
    document.querySelector("#" + idmsg + " li.letra").style.color = 'red';
    passou = false;
  }
  if (numeros.test(elemento)) {
    document.querySelector("#" + idmsg + " li.numero").style.color = 'green';
    passou = passou & true;
  } else {
    document.querySelector("#" + idmsg + " li.numero").style.color = 'red';
    passou = false;
  }
  if (simbolos.test(elemento)) {
    document.querySelector("#" + idmsg + " li.simbolo").style.color = 'green';
    passou = passou & true;
  } else {
    document.querySelector("#" + idmsg + " li.simbolo").style.color = 'red';
    passou = false;
  }
  return passou;
}
function criticaSenhas() {
  if (criticaChange('senha', 'msgsenha') && criticaChange('confirmaSenha', 'msgconfirmaSenha')) {
    if (document.getElementById('senha').value !== document.getElementById('confirmaSenha').value) {
      document.getElementById("msgerro").innerText = 'As senhas devem ser iguais';
      document.getElementById("msgerro").style.color = 'red';
      document.getElementById('botaoLogin').disabled = true;
    } else {
      document.getElementById("msgerro").innerText = 'Tudo numa boa';
      document.getElementById("msgerro").style.color = 'green';
      document.getElementById('botaoLogin').disabled = false;
    }
  } else {
    document.getElementById("msgerro").innerText = 'Preencha as senhas';
    document.getElementById("msgerro").style.color = 'red';
    document.getElementById('botaoLogin').disabled = true;
  }
}