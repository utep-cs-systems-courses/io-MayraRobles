void canon_in_D_state_advance() /* Plays canon in D */
{
  static int cur_note = 0;
 
  switch (cur_note) {
  case 0:
    buzzer_set_period(A5);
    cur_note ++;
    break;
  case 1:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 2:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 3:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 4:
    buzzer_set_period(G5);
    cur_note ++;
    break;
  case 5:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 6:
    buzzer_set_period(A5);
    cur_note ++;
    break;
  case 7:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 8:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 9:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 10:
    buzzer_set_period(G5);
    cur_note ++;
    break;
  case 11:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 12:
    buzzer_set_period(A5);
    cur_note ++;
    break;
  case 13:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 14:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 15:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 16:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 17:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 18:
    buzzer_set_period(Db5);
    cur_note ++;
    break;
  case 19:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 20:
    buzzer_set_period(D5);
    cur_note ++;
    break;
  case 21:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 22:
    buzzer_set_period(E5);
    cur_note ++;
    break;
  case 23:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 24:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 25:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 26:
    buzzer_set_period(G5);
    cur_note ++;
    break;
  case 27:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 28:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 29:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 30:
    buzzer_set_period(D5);
    cur_note ++;
    break;
  case 31:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 32:
    buzzer_set_period(E5);
    cur_note ++;
    break;
  case 33:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 34:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 35:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 36:
    buzzer_set_period(F4_SHARP);
    cur_note ++;
    break;
  case 37:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 38:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 39:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 40:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 41:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 42:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 43:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 44:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 45:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 46:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 47:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 48:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 49:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 50:
    buzzer_set_period(F4_SHARP);
    cur_note ++;
    break;
  case 51:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 52:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 53:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 54:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 55:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 56:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 57:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 58:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 59:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 60:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 61:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 62:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 63:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 64:
    buzzer_set_period(F4_SHARP);
    cur_note ++;
    break;
  case 65:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 66:
    buzzer_set_period(E4);
    cur_note ++;
    break;
  case 67:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 68:
    buzzer_set_period(F4_SHARP);
    cur_note ++;
    break;
  case 69:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 70:
    buzzer_set_period(E4);
    cur_note ++;
    break;
  case 71:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 72:
    buzzer_set_period(D4);
    cur_note ++;
    break;
  case 73:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 74:
    buzzer_set_period(E4);
    cur_note ++;
    break;
  case 75:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 76:
    buzzer_set_period(F4_SHARP);
    cur_note ++;
    break;
  case 77:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 78:
    buzzer_set_period(G4);
    cur_note ++;
    break;
  case 79:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 80:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 81:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 82:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 83:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 85:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 86:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 87:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 88:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 89:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 90:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 91:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 92:
    buzzer_set_period(Db5);
    cur_note ++;
    break;
  case 93:
    buzzer_set_period(0);
    cur_note ++; 
    break;
  case 94:
    buzzer_set_period(D5);
    cur_note ++;
    break;
  case 95:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 96:
    buzzer_set_period(A4);
    cur_note ++;
    break;
  case 97:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 98:
    buzzer_set_period(B4);
    cur_note ++;
    break;
  case 99:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 100:
    buzzer_set_period(Db5);
    cur_note ++;
    break;
  case 101:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 102:
    buzzer_set_period(D5);
    cur_note ++;
    break;
  case 103:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 104:
    buzzer_set_period(E5);
    cur_note ++;
    break;
  case 105:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 106:
    buzzer_set_period(F5_SHARP);
    cur_note ++;
    break;
  case 107:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 108:
    buzzer_set_period(G5);
    cur_note ++;
    break;
  case 109:
    buzzer_set_period(0);
    cur_note ++;
    break;
  case 110:
    buzzer_set_period(A5);
    cur_note ++;
    break;
  case 111:
    buzzer_set_period(0);
    cur_note = 0;
    break;
  } 
}
