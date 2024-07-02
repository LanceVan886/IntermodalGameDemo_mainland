var cfgCallJsBacks={};
var CFGameUser = window.webkit.messageHandlers;
var CFGameOpenApi = window.webkit.messageHandlers;
var CFGameLife = window.webkit.messageHandlers;

var cf_game={
    User:{
        getUserInfo: function (callback) {
            console.log("getUserInfo()");
            var invokeId = getInvokeId();
            cfgCallJsBacks[invokeId] = callback;
            CFGameUser.getUserInfo.postMessage(invokeId);
        }
    },
    OpenApi:{
        getBaseInfo: function (callback) {
                    console.log("getBaseInfo()");
                    var invokeId = getInvokeId();
                    cfgCallJsBacks[invokeId] = callback;
                    CFGameOpenApi.getBaseInfo.postMessage(invokeId);
        },
        
        getWindowSafeArea: function (callback) {
                       console.log("getWindowSafeArea()");
                       var invokeId = getInvokeId();
                       cfgCallJsBacks[invokeId] = callback;
                       CFGameOpenApi.getWindowSafeArea.postMessage(invokeId);
        },
            
        openChargePage: function () {
            var invokeId = getInvokeId();
            console.log("openChargePage()");
            CFGameOpenApi.openChargePage.postMessage(getInvokeId);
        },

        closeGamePage: function () {
            var invokeId = getInvokeId();
            console.log("closeGamePage()");
            CFGameOpenApi.closeGamePage.postMessage(invokeId);
        }

    },
    GameLife:{
        gameLoadFailed:function(){
            console.log("gameLoadFailed()");
            CFGameLife.gameLoadFailed.postMessage();
        },
        joinGame:function(userId){
            console.log("joinGame()");
            CFGameLife.joinGame.postMessage(userId);
        },
        gamePrepare:function(userId){
            console.log("gamePrepare()");
            CFGameLife.gamePrepare.postMessage(userId);
        },
        cancelPrepare:function(userId){
            console.log("cancelPrepare()");
            CFGameLife.cancelPrepare.postMessage(userId);
        },
        gameTerminated:function(userId){
            console.log("gameTerminated()");
            CFGameLife.gameTerminated.postMessage(userId);
        },
        reportGameSeats:function(userIds){
            console.log("call reportGameSeats()");
            CFGameLife.reportGameSeats.postMessage(userIds);
        },
        saveResultPicture:function(data){
            console.log("call saveResultPicture()");
            CFGameLife.saveResultPicture.postMessage(data);
        }
    },
};

function getInvokeId(){
    var byteArray = new Uint32Array(1);
    window.crypto.getRandomValues(byteArray);
    return byteArray[0].toString();
}

function callCFJs(invokeId, data) {
    var callback = cfgCallJsBacks[invokeId];
    if(callback == undefined){
        console.log("callback is null !");
    } else {
        callback(JSON.stringify(data));
        delete (cfgCallJsBacks[invokeId]);
    }
}

window.CFGame=cf_game;
