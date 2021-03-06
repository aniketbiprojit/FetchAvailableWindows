const path = require('path');
const childProcess = require('child_process');
const { promisify } = require('util');

const { setTimeout } = require('timers');

const execFile = promisify(childProcess.execFile);

async function run(binPath) {
	const executableLocation =
		binPath ||
		path.join('C:\\Users\\Aniket Biprojit\\source\\repos\\ConsoleApplication1\\x64\\Release','GetForegroundWindow.exe'		);
	setTimeout(async () => {
        try {
            
            const pyprocess = execFile(executableLocation);
    
            const output = await pyprocess;
            
            let data = output.stdout.toString();
            
            console.log(data);
        } catch (error) {
            console.error(error)
        }
	}, );
	// data.platform = 'windows';
	// data.name = data.name.toLowerCase();
	// data.app = data.name;

	// return data;
}

run();