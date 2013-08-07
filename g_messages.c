

void destroyMessage(game_hudelem_t* hudelem){

    if(!hudelem || !hudelem->inuse)
        return;

    ucolor_t color;

    color.red = 255;
    color.green = 255;
    color.blue = 255;
    color.alpha = 0;

    G_HudSetFadingOverTime(hudelem, 700, color);

}



void showMessage(game_hudelem_t* hudelem, const char* rule, int time){

    if(!hudelem || !hudelem->inuse)
        return;

    ucolor_t color;

    color.red = 255;
    color.green = 255;
    color.blue = 255;
    color.alpha = 255;

    G_HudSetFadingOverTime(hudelem, 700, color);

    G_HudSetText(hudelem, rule);

    Com_AddTimedEvent(time+700, destroyMessage, 1, hudelem);

}



void printRuleForPlayer(client_t *cl){

    if(cl->msgType != 1)
        return;


    char *rule = psvs.messages.ruleStrings[cl->currentAd];

    if(rule == NULL){ //No looping, go to adverts

        cl->msgType++;
        return;
    }

    if(!cl->hudMsg)
        G_SetupHudMessagesForPlayer(cl);

    if(!cl->hudMsg)
        return; //Failure to get hudelem

    G_HudSetPosition(cl->hudMsg, 0, 25, HUDSCRNALIGN_CENTER, HUDSCRNALIGN_TOP, HUDALIGN_CENTER, HUDALIGN_TOP);
    G_HudSetFont(cl->hudMsg, 1.6, HUDFONT_DEFAULT);

    showMessage(cl->hudMsg, rule, 5000);
    cl->currentAd++;
}


void printAdvertForPlayer(client_t *cl){

    if(cl->msgType != 2)
        return;

    char *ad = psvs.messages.adStrings[cl->currentAd];

    if(ad == NULL){
        if(psvs.messages.adStrings[0] == NULL){

            if(cl->hudMsg)
                G_HudDestroy(cl->hudMsg); //Nothing to show

            cl->hudMsg = NULL;
            return;
        }
        cl->currentAd = 0;
        ad = psvs.messages.adStrings[cl->currentAd];
    }

    if(!cl->hudMsg)
        G_SetupHudMessagesForPlayer(cl);

    if(!cl->hudMsg)
        return; //Failure to get hudelem

    G_HudSetPosition(cl->hudMsg, 0, 0, HUDSCRNALIGN_CENTER, HUDSCRNALIGN_TOP, HUDALIGN_CENTER, HUDALIGN_TOP);
    G_HudSetFont(cl->hudMsg, 1.4, HUDFONT_DEFAULT);

    showMessage(cl->hudMsg, ad, 8000);
    cl->currentAd++;
}


void G_SetupHudMessagesForPlayer(client_t* cl){

    ucolor_t glowcolor;
    ucolor_t color;

    color.red = 255;
    color.green = 255;
    color.blue = 255;
    color.alpha = 0;

    glowcolor.red = 0;
    glowcolor.green = 0;
    glowcolor.blue = 0;
    glowcolor.alpha = 0;

    if(cl == NULL)
        return;

    if(!cl->hudMsg)
        cl->hudMsg = G_GetNewHudElem(cl - svs.clients);

    if(!cl->hudMsg)
        return;

    G_HudSetColor(cl->hudMsg, color, glowcolor);


    cl->hudMsg->displayoption = HUDDISPLAY_HIDEINMENU | HUDDISPLAY_FOREGROUND;
    cl->hudMsg->sort = 100;
}




void G_DestroyAdsForPlayer(client_t *cl){

    if(!cl->hudMsg)
        return;

    G_HudDestroy(cl->hudMsg);
    cl->hudMsg = NULL;

}


void G_AddRule(const char* newtext){

    char* textbuf = psvs.messages.msgBuff;
    int len;
    int i;


    int newstrlen = strlen(newtext);

    if(newstrlen < 3)
        return;

    //Find an empty slot to reference this string
    for(i = 0; i < MAX_MESSAGES; i++)
    {
        if(psvs.messages.ruleStrings[i] == NULL)
            break;
    }
    if(i == MAX_MESSAGES){
        Com_PrintWarning("Exceeded the limit of %i rules\n", MAX_MESSAGES);
        return;
    }

    int j = 0;

    while(j < MAX_MSGBUFF)
    {

        //Is our text already there
        if(!Q_stricmp(newtext, textbuf))
        {
            return; //Already an added rule
        }

        len = strlen(textbuf);

        if(!len) //No more added textstrings in buffer
            break;

        textbuf = &textbuf[len+1];
        j += (len + 1);
    }

    if(newstrlen >= MAX_MSGBUFF - j){
        Com_PrintWarning("Exceeded the maximum combined length of all advert and rules\n");
        return;
    }
    //append the new text string to our buffer
    Q_strncpyz(textbuf, newtext, newstrlen+1);
    //Reference it now
    psvs.messages.ruleStrings[i] = textbuf;
}





void G_AddAdvert(const char* newtext){

    char* textbuf = psvs.messages.msgBuff;
    int len;
    int i;

    int newstrlen = strlen(newtext);

    if(newstrlen < 3)
        return;

    //Find an empty slot to reference this string
    for(i = 0; i < MAX_MESSAGES; i++)
    {
        if(psvs.messages.adStrings[i] == NULL)
            break;
    }
    if(i == MAX_MESSAGES){
        Com_PrintWarning("Exceeded the limit of %i adverts\n", MAX_MESSAGES);
        return;
    }

    int j = 0;

    while(j < MAX_MSGBUFF)
    {

        //Is our text already there
        if(!Q_stricmp(newtext, textbuf))
        {
            return; //Already an added rule
        }

        len = strlen(textbuf);

        if(!len) //No more added textstrings in buffer
            break;

        textbuf = &textbuf[len+1];
        j += (len + 1);
    }

    if(newstrlen >= MAX_MSGBUFF - j){
        Com_PrintWarning("Exceeded the maximum combined length of all advert and rules\n");
        return;
    }
    //append the new text string to our buffer
    Q_strncpyz(textbuf, newtext, newstrlen+1);
    //Reference it now
    psvs.messages.adStrings[i] = textbuf;
}




void InitMotd(){

    const char *motd = SV_GetMessageOfTheDay();
    int i = 0;
    int j = 0;
    int lSCounterI = 0;
    int lSCounterO = 0;
    int overallcount = 0;

    char *outputstr = svse.motd;
    const char *inputstr = motd;

    while( inputstr[i] && (overallcount+1) < sizeof(svse.motd)){

        if( inputstr[i] == ' '){ /*Save the positions of the last recent wordspacer*/
            lSCounterI = i;
            lSCounterO = j;
        }

        if(inputstr[i] == '^' && inputstr[i+1] >= '0' && inputstr[i+1] <= '9'){
            i += 2;
            continue;

        }else{

            outputstr[j] = inputstr[i];
        }

        if( j >= 64){

            if(lSCounterO > 40)
            {
                j = lSCounterO;
                i = lSCounterI;
            }

            outputstr[j] = '\n';

            outputstr += j+1;
            inputstr += i+1;
            overallcount++;

            lSCounterO = 0;
            lSCounterI = 0;

            i = 0;
            j = 0;
            continue;
        }
        j++;
        i++;
        overallcount++;
    }
    outputstr[j] = 0;
}



void G_SwitchToRules(client_t *cl){

        cl->msgType++;
}

void G_RemoveMotd(game_hudelem_t* hudelem1, game_hudelem_t* hudelem2){
	G_HudSetMovingOverTime( hudelem1, 800, -800, 90);
	G_HudSetMovingOverTime( hudelem2, 800, 800, 90);
	Com_AddTimedEvent(800, G_HudDestroy, 1, hudelem1);
	Com_AddTimedEvent(800, G_HudDestroy, 1, hudelem2);
}



#define MAX_LENGTH_30 30
#define MAX_LENGTH_20 46
#define MAX_LENGTH_14 66


void G_ShowMotd(client_t* cl)
{
    game_hudelem_t* hudelem1;
    game_hudelem_t* hudelem2;

    int len = strlen(svse.motd);
    float fontscale;

    unsigned int clnum = cl - svs.clients;


    if(len < 3){
        cl->msgType++;
        return;//No message of the day
    }
    if(len < 30)
        fontscale = 3.0;

    else if(len < 46)
        fontscale = 2.0;

    else fontscale = 1.4;

    ucolor_t glowcolor;
    ucolor_t color;

    color.red = 204;
    color.green = 255;
    color.blue = 204;
    color.alpha = 255;

    glowcolor.red = 76;
    glowcolor.green = 153;
    glowcolor.blue = 76;
    glowcolor.alpha = 10;


    Com_DPrintf("Draw Message of the Day of client num: %i\n", clnum);

    hudelem1 = G_GetNewHudElem(clnum);

    if(!hudelem1)
        return;

    hudelem2 = G_GetNewHudElem(clnum);

    if(!hudelem2){
        G_HudDestroy(hudelem1);
        return;
    }


    G_HudSetColor(hudelem1, color, glowcolor);
    G_HudSetColor(hudelem2, color, glowcolor);

    G_HudSetPosition(hudelem1, 800, 90, HUDSCRNALIGN_CENTER, HUDSCRNALIGN_MIDDLE, HUDALIGN_CENTER, HUDALIGN_MIDDLE);
    G_HudSetPosition(hudelem2, -800, 90, HUDSCRNALIGN_CENTER, HUDSCRNALIGN_MIDDLE, HUDALIGN_CENTER, HUDALIGN_MIDDLE);

    G_HudSetFont(hudelem1, fontscale, HUDFONT_OBJECTIVE);
    G_HudSetFont(hudelem2, fontscale, HUDFONT_OBJECTIVE);

    hudelem1->displayoption = HUDDISPLAY_HIDEINMENU | HUDDISPLAY_FOREGROUND;
    hudelem2->displayoption = HUDDISPLAY_HIDEINMENU | HUDDISPLAY_FOREGROUND;
    hudelem1->sort = 100;
    hudelem2->sort = 99;

    G_HudSetText(hudelem1, svse.motd);
    G_HudSetText(hudelem2, svse.motd);

    G_HudSetMovingOverTime(hudelem1, 800, 0, 90);
    G_HudSetMovingOverTime(hudelem2, 800, 0, 90);

    Com_AddTimedEvent(10800, G_RemoveMotd, 2, hudelem1, hudelem2);
    Com_AddTimedEvent(15000, G_SwitchToRules, 1, cl);

}
