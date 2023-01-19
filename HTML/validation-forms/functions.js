/**
 * Funções para tratamento de formulários.
*/

/*
 * Verifica se o campo é vazio ou se é inválido.
*/
function verifyField(obj,msgEmpty,msgInvalid) {
  if(obj.value === ''){
    obj.setCustomValidity(msgEmpty);
  }else{
    obj.setCustomValidity(msgInvalid);
  }
}
/*
 * Verifica o tipo de formulário selecionado e atualiza a mensagem de desconto
*/
function selectType(obj) {
  let labelAutorized = document.getElementById("confirmed");
  let buttonSubmit = document.getElementById("join_submit");
  if(labelAutorized !== null && buttonSubmit !== null){
    buttonSubmit.disabled = true;
    if(obj.id === "docas"){
      labelAutorized.innerHTML = "<input type=\"checkbox\" name=\"confirmed\" value=\"true\" onchange=\"confirmedSelect(this,'join_submit')\" /> Autorizo o desconto de 3% do salário base em folha de pagamento.";
    }else if(obj.id === "aposentados"){
      labelAutorized.innerHTML = "<input type=\"checkbox\" name=\"confirmed\" value=\"true\" onchange=\"confirmedSelect(this,'join_submit')\" /> Autorizo o desconto de 5% do salário mínimo.";
    }else if(obj.id === "trabalhador"){
      labelAutorized.innerHTML = "<input type=\"checkbox\" name=\"confirmed\" value=\"true\" onchange=\"confirmedSelect(this,'join_submit')\" /> Autorizo o desconto de 5% da mensalidade (DAS).";
    }
  }
}
/*
 * Verifica se o checkbox de autorização foi marcado
*/
function confirmedSelect(obj,id){
  let buttonSubmit = document.getElementById(id);
  if(buttonSubmit !== null){
    if(obj.checked){
      buttonSubmit.disabled = false;
    }else{
      buttonSubmit.disabled = true;
    }
  }
}
/*
 * Valida os dados do formulário e cria JSON.
*/
function validateForm(name){
  let formObject = document.getElementById(name);
  let formSize = formObject.length;
  let formData = {token: ""};
  for(let i=0;i<formSize;i++){
    switch(formObject[i].id){
      case 'g-recaptcha-response':
        formData['token'] = formObject[i].value;        
        break;
      default:
        if(formObject[i].type !== 'button' && formObject[i].type !== 'submit' && formObject[i].type !== 'reset'){
          formData[formObject[i].name] = formObject[i].value;
        }
        break;
    };
  }
  return formData;
}
/*
 * Prepara e envia dos dados do formulário em formato JSON.
*/
function submitForm(name){
  event.preventDefault();
  let formObject = document.getElementById(name);
  let formSize = formObject.length;
  let button = '';
  let formData = {token: ""};
  for(let i=0;i<formSize;i++){
    switch(formObject[i].nodeName){
      case 'INPUT':
      case 'TEXTAREA':
        formObject[i].disabled = true;
        switch(formObject[i].id){
          case 'submit':
            button = formObject[i];
            break;
          case 'g-recaptcha-response':
            formData['token'] = formObject[i].value;        
            break;
          default:
            formData[formObject[i].name] = formObject[i].value;
            break;
        };
        break;
    };
  }
  if(formData['token'] !== ""){
    button.value = "ENVIANDO";
    fetch(formObject.action,{
      method: "POST",
      headers: {'Content-Type': 'application/json'},
      body: JSON.stringify(formData)
    }).then((response) => {
      if(response.status === 200){
        response.json().then((result) => {
          if(result.success){
            button.value = "ENVIADO";
          }else{
            button.value = "NÃO ENVIADO";
            alert("Não enviado, tente novamente.\nCaso o problema persista tente novamente mais tarde.");
            location.reload();
          }
        }).catch((err) => {
          button.value = "NÃO ENVIADO";
          alert("Não enviado, tente novamente.\nCaso o problema persista tente novamente mais tarde.");
          location.reload();
        });
      }else{
        button.value = "NÃO ENVIADO";
        alert("Não enviado, tente novamente.\nCaso o problema persista tente novamente mais tarde.");
        location.reload();
      }
    }).catch((err) => {
      button.value = "NÃO ENVIADO";
      alert("Não enviado, tente novamente.\nCaso o problema persista tente novamente mais tarde.");
      location.reload();
    });
  }else{
    button.value = "NÃO ENVIADO";
    alert("Não enviado, tente novamente.\nCaso o problema persista tente novamente mais tarde.");
    location.reload();
  }
};
/*
 * Cria PDF para impressão do formulário.
*/
function printForm(name){
  let formData = validateForm(name);
  console.log(formData);
}
let max_date = new Date();
let ad = document.getElementById('admissao');
if(ad !== null){
  ad.max = new Date(max_date.getTime() - (new Date().getTimezoneOffset() * 60000)).toISOString().split("T")[0];
}
let na = document.getElementById('nascimento');
if(na !== null){
  max_date.setFullYear(max_date.getFullYear()-18);
  na.max = new Date(max_date.getTime() - (new Date().getTimezoneOffset() * 60000)).toISOString().split("T")[0];
}