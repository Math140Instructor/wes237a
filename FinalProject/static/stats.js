let statsIntervalId = null;
let failedStatsRequests = 0;
const MAX_FAILURES = 3;

function stopStatsUpdates() {
    if (statsIntervalId !== null) {
        clearInterval(statsIntervalId);
        statsIntervalId = null;
        console.log("Stopped stats polling");
    }
}

function updateStats() {
    console.log("updateStats called");

    fetch("/stats")
        .then(function(response) {
//             console.log("raw response:", response);
//             console.log("status:", response.status);
//             console.log("ok:", response.ok);

            if (!response.ok) {
                throw new Error("HTTP error " + response.status);
            }

            return response.json();
        })
        .then(function(data) {
            failedStatsRequests = 0;

            console.log("json data:", data);

            const filterEl = document.getElementById("filter_status");
            const fpsEl = document.getElementById("fps");
            const modeEl = document.getElementById("mode");
            const widthEl = document.getElementById("width");
            const heightEl = document.getElementById("height");
            const fdEl = document.getElementById("face_detected");
            const ledEl = document.getElementById("left_eye_detected");
            const redEl = document.getElementById("right_eye_detected");
            const bufferSizeEl = document.getElementById("buffersize");
            const fourccEl = document.getElementById("fourcc");

            if (!filterEl || !fpsEl || !modeEl) {
                throw new Error("One or more HTML elements were not found");
            }

            filterEl.textContent = data.filter_status;
            fpsEl.textContent = data.fps;
            modeEl.textContent = data.mode;
            widthEl.textContent = data.width;
            heightEl.textContent = data.height;
            fdEl.textContent = data.face_detected;
            ledEl.textContent = data.left_eye_detected;
            redEl.textContent = data.right_eye_detected;
            bufferSizeEl.textContent = data.buffersize;
            fourccEl.textContent = data.fourcc;
        })
        .catch(function(error) {
            failedStatsRequests++;
            console.log("Stats update error:", error);

            if (failedStatsRequests >= MAX_FAILURES) {
                stopStatsUpdates();
            }
        });
}

statsIntervalId = setInterval(updateStats, 1000);
updateStats();