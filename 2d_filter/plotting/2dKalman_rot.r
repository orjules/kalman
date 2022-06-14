data <- read.table(
    "./2d_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "./2d_filter/images/plot_rot.png"
)

plot(
    data$Time, data$Rot,
    ylim = c(-2, 1),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Angular velocity in rad/s | Angle in rad",
    main = "Kalman Filter simulation - Rotation",
    sub = sprintf("Error in measurement: %1.2f, Q for rotation speed: %1.2f", data[1, "RotError"], data[1, "Q_rot"])
)
lines(data$Time, data$MeasRot, col = "red")
abline(h = 0)
abline(h = -1.570796)

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State rotation", "Measured rotation speed"),
        col = c("blue", "red"),
        pch = c(1, 1))

dev.off()