/* 
DASLights-datastructure.h

*/

// defined names for struct members
// stage type values
#define stageActionStatic 0
#define stageActionTimed 1
#define stageActionGoto 2
#define stageActionStop 3

// stage status values
#define stageTypeWait 0
#define stageTypePrepare 1
#define stageTypeShoot 2
#define stageTypeWarning 3
#define stageTypeStop 4

// lamp states - bitwise states
#define lampSteadyAllOff 0
#define lampFlashRed 32
#define lampFlashYellow 16
#define lampFlashGreen 8
#define lampSteadyRed 4
#define lampSteadyYellow 2
#define lampSteadyGreen 1


// stage struct will hold the details of an individual stage
//Example:   stage myStage = { stageActionStatic, stageTypePrepare, 10, lampSteadyRed, 3 };
typedef struct
{
    int action; // what kind of stage - Static/Timed/Goto
    int type;   // Wait/Prepare/Shoot/Warning/Stop
    long time; // Length of the stage in seconds 
    int lamps; // Which lamps are active during this stage
    int buzzer; // How many buzzers to sound at the START of the stage
  //  char *message; // message to display if any
} stage ;  
 
// shootingSequence struct will hold an entire sequence
// which comprises of a set of stages and associated data
struct shootingSequence
{
  char *name;
  char *displayName;
  int detailLength;
  stage stagelist[10];
} ;

// define the actual sequence data
shootingSequence Sequences[] = {
  {
    "World Archery 3 arrows - single detail",
    "WA-120s SNG",
    120,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 90, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionStatic, stageTypePrepare, 10, lampSteadyRed, 3 },
      { stageActionGoto, stageTypeStop, 0, lampSteadyRed, 0 }
    }
  },
  {
    "World Archery 3 arrows - double detail",
    "WA-120s DBL",
    120,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 90, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 90, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionStatic, stageTypePrepare, 10, lampSteadyRed, 3 },
      { stageActionGoto, stageTypeStop, 0, lampSteadyRed, 0 }
    }
  },
  {
    "World Archery 6 arrows - single detail",
    "WA-240s SNG",
    240,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 210, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 3 },
      { stageActionGoto, stageTypeStop, 0, lampSteadyRed, 0 }
    }
  },
  {
    "World Archery 6 arrows - double detail",
    "WA-240s DBL",
    240,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 210, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 210, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 3 },
      { stageActionGoto, stageTypeStop, 0, lampSteadyRed, 0 }
    }
  },
  {
    "Archery GB - single detail",
    "AGB-240s SNG",
    240,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 20, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 210, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 3 },
      { stageActionGoto, stageTypeStop, 0, lampSteadyRed, 0 }
    }
  },
  {
    "Continuous 2 minute World Archery",
    "WA-120s CONT"
    120,
    {
      { stageActionStatic, stageTypeWait, 0, lampSteadyRed, 0 },
      { stageActionTimed, stageTypePrepare, 10, lampSteadyRed, 2 },
      { stageActionTimed, stageTypeShoot, 90, lampSteadyGreen, 1 },
      { stageActionTimed, stageTypeWarning, 30, lampSteadyYellow, 0 },
      { stageActionGoto, stageTypeStop, 1, lampSteadyRed, 3 }
    }
  }
};


