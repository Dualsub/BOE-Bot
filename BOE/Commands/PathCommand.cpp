// #include "PathCommand.h"
// #include "Despacito.h" // Fil som inkluderar låten Despacito.
// #include "String.h"

// PathCommand::PathCommand(Wheels* wheels, Speaker* speaker, String* sequence, size_t sequenceLength)
// {
//     this->wheels = wheels;
//     this->speaker = speaker;
//     this->sequence = sequence;
//     this->sequenceLength = sequenceLength;
// }

// bool PathCommand::Excecute() 
// {
//     if(wheels == nullptr || speaker == nullptr || sequenceLength <= 0) // Om vår pekare till hjulen är null så returnerar att vi misslyckats med kommandot.
//         return false;

    
//     // for (size_t i = 0; i < sequenceLength; i++)
//     // {
//     //     String command = String(sequence[i]);
//     //     Serial.println(command);
//     //     switch(command.charAt(0)) 
//     //     {
//     //         case 's':
//     //             // Spela låt
//     //             speaker->PlaySong(notes, noteDurations, numNotes);
//     //         break;
//     //         case 'f':
//     //             // Framåt
//     //             int fdistance = command.substring(1).toInt();
//     //             wheels->ManeuverDistance(fdistance);
//     //         break;

//     //         case 'r':
//     //             // Vänster-sväng
//     //             // Kollar om svängen ska framåt eller bakåt.
//     //             if(command.charAt(1) == 'f') 
//     //             {
//     //                 int rangle = command.substring(2).toInt();
//     //                 wheels->ManeuverAngle(rangle, true);
//     //             } 
//     //             else if(command.charAt(1) == 'b')
//     //             {
//     //                 int rangle = command.substring(2).toInt();
//     //                 wheels->ManeuverAngle(rangle, true, true);
//     //             }
//     //         break;

//     //         case 'l':
//     //             // Vänster-sväng
//     //             // Kollar om svängen ska framåt eller bakåt.
//     //             if(command.charAt(1) == 'f') 
//     //             {
//     //                 int langle = command.substring(2).toInt();
//     //                 wheels->ManeuverAngle(langle, false);
//     //             } 
//     //             else if(command.charAt(1) == 'b')
//     //             {
//     //                 int langle = command.substring(2).toInt();
//     //                 wheels->ManeuverAngle(langle, false, true);
//     //             }
            
//     //         break;

//     //         case 'b':
//     //             // Backa
//     //             int bdistance = command.substring(1).toInt();
//     //             wheels->ManeuverDistance(bdistance, true);
//     //         break;

//     //         default:
//     //             Serial.println("Nothing");
//     //         break;
//     //     }
    
//     // }
//     // return true;
    





//     wheels->ManeuverDistance(150);
//     wheels->ManeuverAngle(175, false);
//     wheels->ManeuverDistance(320);
//     wheels->ManeuverAngle(138, true);
//     wheels->ManeuverDistance(200);
//     speaker->PlaySong(notes, noteDurations, numNotes);
//     wheels->ManeuverAngle(110, true);
//     wheels->ManeuverAngle(120, false, true);
//     wheels->ManeuverDistance((wheels->wheelDistance)+180);
//     wheels->ManeuverAngle(175, false);
//     wheels->ManeuverDistance(320);
//     wheels->ManeuverAngle(130, true);
//     wheels->ManeuverDistance(200);
// }