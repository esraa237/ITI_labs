/*Create a Base Class Clock, this class initials the starting time for any clock object 
1. Properties:    
a) public -> hours, minutes, seconds 
b) private ->  IntervalId 
 */

class Clock{
    #intervalId;
/*2. Constructor: 
a) Accept an initial time (e.g., HH:MM:SS) as a string. 
b) Parse the time and store it as hours, minutes, and seconds Properties. */
    constructor(initialTime){
        this.time=initialTime.split(":");//variable
        this.hours=parseInt((this.time[0])%60)+parseInt((this.time[1])/60)+parseInt((this.time[2])/60);
        this.minutes=parseInt((this.time[1])%60)+parseInt((this.time[0])/60);
        this.seconds=parseInt((this.time[2])%60);
    }
    set intervalId(value){this.#intervalId=value;}
    get intervalId(){return this.#intervalId;}

    // 3. Static Member: 
    // a) Add a static method formatTime(hours, minutes, seconds) to format the time as 
    // HH:MM:SS from the class properties 
    static formatTime(hours,minutes,seconds){
        return `${hours}:${minutes}:${seconds}`;
    }

    // 4. Private Methods: 
    // a) Create a private method #tick() to increment the clock's time by one second. 
    #tick(){
        this.seconds++;
        if(this.seconds>=60){
            this.minutes+=parseInt(this.seconds/60);
            this.seconds%=60;
        }
        if(this.minutes>=60){
            this.hours+=parseInt(this.minutes/60);
            this.minutes%=60;
        }
    }

    //5. Public Methods: 
    // a) start(): Starts the clock using setInterval to call the #tick() method every second. 
    start(){    
        this.#intervalId=setInterval(()=>{
            this.#tick();
            console.log(`Time now: ${this.getTime()}`);
        },1000);
    }
    // b) stop(): Stops the clock. 
    stop(){
        if (this.#intervalId) {
            clearInterval(this.#intervalId);
            console.log("Time is stopped");
        }
    }
    //c. getTime(): Returns the current time formatted as HH:MM:SS (now it’s time to use 
    // formatTime method to convert properties to string) 
    getTime(){
        return `${Clock.formatTime(this.hours,this.minutes,this.seconds)}`;
    }
}

// let clock= new Clock("2:58:59");
// console.log(clock.constructor.name);
// clock.start();
//setTimeout(clock.stop,4000);



// Create a Subclass AlarmClock: 
//  Inherit from the Clock class. 
//  private alarmTime property to store the alarm time as , HH:MM:SS 

class AlarmClock extends Clock{
    #alarmTime;
    #checkIntervalId;

    //  Constructor: 
    // o Accept an additional parameter alarmTime (e.g., HH:MM:SS) for the alarm. 
    constructor(initialTime,alarmTime){
        super(initialTime);
        this.#alarmTime=alarmTime;
    }
    //  Private Methods: 
    // o Create a private method #checkAlarm() to compare the current time with the 
    // alarm time. 
    #checkAlarm(){
        if(this.getTime()==this.#alarmTime){
            console.log("Alarm! Wake up!");
            this.stop();
        }
    }
    //  Public Methods: 
    // o Override the start() method to call #checkAlarm() every second. 
        start(){
            super.start();
            this.#checkIntervalId=setInterval(()=>{
                console.log(`check time:${this.getTime()} and alarm: ${this.#alarmTime}`);
                this.#checkAlarm();
            },1000);
        }
    // o Add setAlarm(newAlarmTime) to update the alarm time.
    get alarmTime(){return this.#alarmTime};
    set alarmTime(value){this.#alarmTime=value};
}
let alarmClock=new AlarmClock("14:20:55","14:21:0");
alarmClock.start();
setTimeout(()=>{alarmClock.alarmTime="14:21:5";},6000);