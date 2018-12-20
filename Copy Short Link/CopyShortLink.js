(function() {

if (window.top === window) {

	function handleMessage(event) {

		if (event.name === "copyShortLink") {

			var links = document.getElementsByTagName("link");
			for (var i = 0; i < links.length; i++) {
				var link = links[i];
				if (link.rel == "shorturl" ||
					link.rel == "shortlink" ||
					link.rev == "canonical") {
					processResult(link.href);
					return;
				}
			}

			switch (document.location.host) {
				case "letterboxd.com":
					var inputs = document.getElementsByTagName("input");
					for (x in inputs) {
						if ((new String(inputs[x].value)).match(/^https?:\/\/boxd.it\/[A-Za-z0-9]+/)) {
							processResult(inputs[x].value);
							return;
						}
					}
					break;
				case "www.youtube.com":
					if (result = document.location.href.match(/https?:\/\/www\.youtube\.com\/watch\?v=([A-Za-z0-9]+)/)) {
						processResult("http://youtu.be/"+result[1]);
						return;
					}
					break;
			}

			processResult(null);

		} else if (event.name === "showResult") {

			var url = event.message["url"];
			var success = (url != null);
			showResult(success, url);

		}

	};

	function processResult(url) {

		var userInfo = {"url": url};
		safari.extension.dispatchMessage("processResult", userInfo);

	};

	function showResult(success, url) {

		var removeOverlay = function(event) {
			var overlay = document.getElementById("com-junecloud-copyshortlink-overlay");
			if (overlay) {
				event.preventDefault();
				event.stopPropagation();
				overlay.style.opacity = "0";
				document.removeEventListener("keydown", self, false);
				setTimeout(function(){
					if (overlay) document.body.removeChild(overlay);
				},500);
			}
		}

		var overlay = document.getElementById("com-junecloud-copyshortlink-overlay");
		if (overlay) document.body.removeChild(overlay);

		var overlayObj = document.createElement("div");
		overlayObj.id = "com-junecloud-copyshortlink-overlay";
		overlayObj.onclick = removeOverlay;

		var messageObj = document.createElement("div");
		messageObj.id = "com-junecloud-copyshortlink-message";
		messageObj.onclick = removeOverlay;
		overlayObj.appendChild(messageObj);

		var iconObj = document.createElement("span");
		iconObj.id = "com-junecloud-copyshortlink-icon";
		iconObj.innerText = (success) ? "📋" : "⚠️";
		iconObj.onclick = removeOverlay;
		messageObj.appendChild(iconObj);

		var textObj = document.createElement("span");
		textObj.id = "com-junecloud-copyshortlink-text";
		textObj.innerText = (success) ? url : "No short link found";
		textObj.onclick = removeOverlay;
		messageObj.appendChild(textObj);

		var detailsObj = document.createElement("div");
		detailsObj.id = "com-junecloud-copyshortlink-details";
		detailsObj.innerHTML = (success) ? "This link has been copied to the clipboard.<br/>Click or press any key to dismiss this message." : "This page does not seem to have an official short link.";
		detailsObj.onclick = removeOverlay;
		overlayObj.appendChild(detailsObj);

		document.body.appendChild(overlayObj);
		setTimeout(function(){
			overlayObj.style.opacity = "1";
		},0);

		document.addEventListener("keydown", removeOverlay);

	};

	safari.self.addEventListener("message", handleMessage);

}

})();
